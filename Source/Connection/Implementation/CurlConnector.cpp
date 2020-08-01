#include "CurlConnector.h"

namespace Marsy
{
    ApiResponse CurlConnector::httpGet(std::string url)
    {
        ApiResponse response;
        std::ostringstream str;
        curl_ios<std::ostringstream> ios(str);
        curl_easy easy(ios);
        easy.add<CURLOPT_URL>(url.c_str());
        easy.add<CURLOPT_SSL_VERIFYPEER>(false);
        easy.add<CURLOPT_FOLLOWLOCATION>(1L);
        easy.add<CURLOPT_TIMEOUT>(30);
        try
        {
            easy.perform();
        }
        catch (curl_easy_exception &error)
        {
            if(error.get_code() == CURLE_OPERATION_TIMEDOUT)
            {
                response.status = ResponseStatus::timeOut;
            }
            else
            {
                response.status = ResponseStatus::otherError;
            }
            return response;
        }
        
        auto status = easy.get_info<CURLINFO_RESPONSE_CODE>();
        response.status = parseStatus(status.get());
        response.payload = str.str();
        return response;
    }

    ApiResponse CurlConnector::httpPost(std::string url, std::string payload)
    {
        ApiResponse response;
        std::ostringstream str;
        curl_ios<std::ostringstream> ios(str);
        curl_easy easy(ios);
        curl_header header;
        header.add("Content-Type: application/json");
        easy.add<CURLOPT_POST>(true);
        easy.add(curl_pair<CURLoption, curl_header>(CURLOPT_HTTPHEADER, header));
        easy.add(curl_pair<CURLoption, std::string>(CURLOPT_POSTFIELDS, payload));
        easy.add<CURLOPT_URL>(url.c_str());
        easy.add<CURLOPT_SSL_VERIFYPEER>(false);
        easy.add<CURLOPT_FOLLOWLOCATION>(1L);
        easy.add<CURLOPT_TIMEOUT>(30);
        try
        {
            easy.perform();
        }
        catch (curl_easy_exception &error)
        {
            if(error.get_code() == CURLE_OPERATION_TIMEDOUT)
            {
                response.status = ResponseStatus::timeOut;
            }
            else
            {
                response.status = ResponseStatus::otherError;
            }
            return response;
        }
        
        auto status = easy.get_info<CURLINFO_RESPONSE_CODE>();
        response.status = parseStatus(status.get());
        response.payload = str.str();
        return response;
    }

    ResponseStatus CurlConnector::parseStatus(long status)
    {
        ResponseStatus stat;
        switch(status)
        {
            case 200:
                stat = ResponseStatus::ok;
                break;
            case 400:
                stat = ResponseStatus::badRequest;
                break;
            case 401:
                stat = ResponseStatus::unauthorized;
                break;
            case 404:
                stat = ResponseStatus::notFound;
                break;
            case 500:
                stat = ResponseStatus::internalServerError;
                break;
            case 502:
                stat = ResponseStatus::badGateway;
                break;
            case 503:
                stat = ResponseStatus::serviceUnavailable;
                break;
            case 504:
                stat = ResponseStatus::gatewayTimeout;
                break;
            default:
                stat = ResponseStatus::otherError;
                break;
        }
        return stat;
    }
}