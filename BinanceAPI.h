//
// Created by Pavel Greshnikov on 25.03.2023.
//

#ifndef GPTTRAIDING_BINANCEAPI_H
#define GPTTRAIDING_BINANCEAPI_H

#include <iostream>
#include <string>
#include <cpprest/http_client.h>
#include <cpprest/json.h>

using namespace web;
using namespace web::http;
using namespace web::http::client;
using namespace std;

class BinanceAPI {
public:
    BinanceAPI(const string& api_key) : api_key_(api_key) {
        client_.set_timeout(5000);
        client_.set_default_headers({{"X-MBX-APIKEY", api_key_}});
    }

    json::value get_klines(const string& symbol, const string& interval) {
        string url = "https://api.binance.com/api/v3/klines";
        uri_builder builder(url);
        builder.append_query("symbol", symbol);
        builder.append_query("interval", interval);
        builder.append_query("limit", "1000");

        http_request request(methods::GET);
        request.set_request_uri(builder.to_uri());
        return client_.request(request).get().extract_json().get();
    }

private:
    http_client client_{"https://api.binance.com/api/v3/"};
    string api_key_;
};

#endif //GPTTRAIDING_BINANCEAPI_H
