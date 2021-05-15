//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherMock.h"

void WeatherMock::clear() {
    response1.status_code = 0;
    response1.text = "";
    is_used = false;
}

void WeatherMock::SetResponse1(std::int32_t status_code, std::string text) {
    response1.status_code = status_code;
    response1.text = text;
}

void WeatherMock::SetResponse2(std::int32_t status_code, std::string text) {
    response2.status_code = status_code;
    response2.text = text;
}

cpr::Response WeatherMock::Get(const std::string& city, const cpr::Url& url) {
    if (!is_used) {
        is_used = true;
        return response1;
    }
    is_used = false;
    return response2;
}
