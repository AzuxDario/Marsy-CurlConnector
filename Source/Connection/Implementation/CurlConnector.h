#ifndef MARSY_CONNECTION_CURLCONNECTOR_H
#define MARSY_CONNECTION_CURLCONNECTOR_H

#include <string>
#include <vector>
#include <optional>

#include "../Interface/IConnector.h"
#include "../Response/Response.h"

namespace Marsy::Connection
{
    class CurlConnector : public IConnector
    {
    public:
        ApiResponse httpGet(std::string url) override;
        ApiResponse httpPost(std::string url, std::string payload) override;
    };
}

#endif