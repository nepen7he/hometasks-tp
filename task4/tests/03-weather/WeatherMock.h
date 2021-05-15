//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#pragma once

#include <gmock/gmock.h>
#include <Weather.h>

class WeatherMock : public Weather {
private:
    cpr::Response response1{}, response2{};
    bool is_used = false;
public:
    void clear();
    void SetResponse1(std::int32_t status_code, std::string text);
    void SetResponse2(std::int32_t status_code, std::string text);
    cpr::Response Get(const std::string& city, const cpr::Url& url) override;
};



