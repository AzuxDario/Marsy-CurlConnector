# Marsy CurlConnector
[![License](https://img.shields.io/github/license/AzuxDario/Marsy-CurlConnector.svg)](https://github.com/AzuxDario/Marsy-CurlConnector/blob/master/LICENSE)
[![Stars](https://img.shields.io/github/stars/AzuxDario/Marsy-CurlConnector.svg)](https://github.com/AzuxDario/Marsy-CurlConnector/stargazers)
[![Issues](https://img.shields.io/github/issues/AzuxDario/Marsy-CurlConnector.svg)](https://github.com/AzuxDario/Marsy-CurlConnector/issues)

This repo contains implementation of `IConnector` for [Marsy](https://github.com/AzuxDario/Marsy). This allows you to get data with Marsy without writting your own implementation. This implementation uses [curlcpp](https://github.com/JosephP91/curlcpp), which is based on [curl](https://curl.haxx.se/).
 
- [Usage](#usage)
- [External libraries](#external-libraries)

# Usage
1. Download files and put them along with Marsy library.
2. Curlcpp is already included.
3. You need to [download](https://curl.haxx.se/download.html) curl for your operating system.
4. In your project settings add path to curl include files `eg. curl-x.x.x-winXX-mingw\include` (curlcpp expect curl files to be in folder `curl\file.h`) and also add path to curl lib files `eg. curl-x.x.x-winXX-mingw\lib`.
5. When you build your program curl may need other `.dll` files alongside, like `libcurl.dll` or files that belong to eg. OpenSSL. You can find them on curl download page for specific version.

# External libraries
 * [curlcpp](https://github.com/JosephP91/curlcpp)