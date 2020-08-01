#ifndef MARSY_CONNECTION_CURLCONNECTOR_H
#define MARSY_CONNECTION_CURLCONNECTOR_H

#include <string>
#include <vector>
#include <optional>
#include <sstream>

#include "curl_easy.h"
#include "curl_header.h"
#include "curl_exception.h"
#include "curl_ios.h"

#include "../Interface/IConnector.h"
#include "../Response/Response.h"

using curl::curl_easy;
using curl::curl_easy_exception;
using curl::curlcpp_traceback;
using curl::curl_ios;
using curl::curl_header;
using curl::curl_pair;

namespace Marsy
{
    class CurlConnector : public IConnector
    {
    public:
        ApiResponse httpGet(std::string url) override;
        ApiResponse httpPost(std::string url, std::string payload) override;
    private:
        ResponseStatus parseStatus(long status);
    };
}

#endif