package gov.nasa.cima.smap.cordova;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.CordovaPlugin;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

import gov.nasa.cima.logging.CimaLogger;
import gov.nasa.cima.logging.LogLevel;
import gov.nasa.cima.smap.SmapApplication;
import gov.nasa.cima.smap.channel.gateway.HttpMethod;
import gov.nasa.cima.smap.channel.gateway.HttpRequest;
import gov.nasa.cima.smap.channel.gateway.ServiceFailureException;
import gov.nasa.cima.smap.utils.AndroidUtils;

import static gov.nasa.cima.smap.SmapApplication.gateway;

public class SmapPlugin extends CordovaPlugin
{
  CimaLogger logger = new CimaLogger();

  @Override
  public boolean execute(String action, JSONArray data, CallbackContext callbackContext) throws JSONException
  {
    if (action.equalsIgnoreCase("sendRequest"))
    {
      sendRequestAsync(action, data, callbackContext);
      return true;
    }
    else if (action.equalsIgnoreCase("log"))
    {
      log(action, data);
      return true;
    }
    else if (action.equalsIgnoreCase("signOut"))
    {
      AndroidUtils.restartApplication(cordova.getActivity());
      return true;
    }
    else if (action.equalsIgnoreCase("auid")) {
      callbackContext.success(SmapApplication.getInstance().getAuid());
      return true;
    }
    else
    {
      logger.error("CIMA plugin received invalid action: " + action);
      return false;
    }
  }

  private void log(String action, JSONArray data)
  {
    try
    {
      LogLevel logLevel = LogLevel.from((String)data.get(0));
      if (logLevel == null)
        logLevel = LogLevel.INFO;
      String message = (String)data.get(1);

      switch (logLevel)
      {
        case DEBUG:
          logger.debug(message);
          break;

        case INFO:
          logger.info(message);
          break;

        case WARN:
          logger.warn(message);
          break;

        case ERROR:
          logger.error(message);
          break;
      }
    }
    catch (JSONException e)
    {
      logger.error("Unable to parse log request in plugin.", e);
    }
  }

  private void sendRequestAsync(final String action, final JSONArray data, final CallbackContext callbackContext)
  {
    cordova.getThreadPool().execute(new Runnable()
    {
      @Override
      public void run()
      {
        HttpRequest request = null;
        try
        {
          JSONObject requestParams = data.getJSONObject(0);

          String url = null;
          if (!requestParams.isNull("url")) {
            url = requestParams.getString("url");
          }
          HttpMethod method = HttpMethod.valueOf(requestParams.getString("method"));
          byte[] payload = null;
          if (!requestParams.isNull("data")) {
            payload = requestParams.get("data").toString().getBytes();
          }
          final boolean isJson = ((payload != null) && (!requestParams.get("data").getClass().equals(String.class)));
          Map headers = null;
          if (!requestParams.isNull("headers")) {
            headers = parseHeaderObject(requestParams.getJSONObject("headers"));
          }

          request = new HttpRequest(url, method, headers, payload);
          logger.info("Executing request: " + request);
          final String response = gateway().sendRequestGetString(request);

          cordova.getActivity().runOnUiThread(new Runnable()
          {
            public void run()
            {
              if (response == null)
              {
                callbackContext.success();
              }
              else if (isJson)
              {
                try
                {
                  callbackContext.success(new JSONObject(response));
                }
                catch (JSONException e)
                {
                  logger.error("Unable to parse response message into JSON: " + response);
                  callbackContext.error("Unable to process response message.");
                }
              }
              else
              {
                callbackContext.success(response);
              }
            }
          });
        }
        catch (final ServiceFailureException e)
        {
          logger.error("Unable to send request: " + request + " due to service failure exception.", e);
          cordova.getActivity().runOnUiThread(new Runnable()
          {
            public void run()
            {
              if (e.failure.getReason().requiresSignout())
              {
                AndroidUtils.restartApplication(cordova.getActivity(), "Your application session has expired.");
                cordova.getActivity().finish();
              }
              else
              {
                callbackContext.error("Unable to communicate with server.");
              }
            }
          });
        }
        catch (Exception e)
        {
          logger.error("Unable to send request: " + request + " due to io exception.", e);
          cordova.getActivity().runOnUiThread(new Runnable()
          {
            public void run()
            {
              callbackContext.error("Unable to communicate with server.");
            }
          });
        }
      }
    });
  }

  private Map parseHeaderObject(final JSONObject jsonHeaders) throws JSONException {
    Map<String, List<String>> headers = new HashMap<String, List<String>>();
    Iterator<String> headerKeys = jsonHeaders.keys();
    while (headerKeys.hasNext()) {
      String headerKey = headerKeys.next();
      // value could be a String or JSONArray<String>
      Object jsonHeaderValuesObject = jsonHeaders.get(headerKey);
      if (jsonHeaderValuesObject.getClass().equals(JSONArray.class)) {
        // process JSONArray<String>
        JSONArray jsonHeaderValues = (JSONArray) jsonHeaderValuesObject;
        List<String> headerValueList = new ArrayList<String>();
        for (int headerValueIndex = 0; headerValueIndex < jsonHeaderValues.length(); headerValueIndex++) {
          String headerValue = jsonHeaderValues.getString(headerValueIndex);
          headerValueList.add(headerValue);
        }
        headers.put(headerKey, headerValueList);
      } else if (jsonHeaderValuesObject.getClass().equals(String.class)) {
        // process String
        String jsonHeaderValue = (String) jsonHeaderValuesObject;
        List<String> headerValueList = new ArrayList<String>();
        headerValueList.add(jsonHeaderValue);
        headers.put(headerKey, headerValueList);
      }
    }
    if (headers.size() > 0) {
      return headers;
    }
    return null;
  }
}
