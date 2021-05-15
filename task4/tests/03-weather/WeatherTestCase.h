
#pragma once

#include <gtest/gtest.h>
#include "WeatherMock.h"

class WeatherTestCase : public ::testing::Test {
public:
    static WeatherMock mock_obj;

    static std::string London_Base;
    static std::string Moscow_Base;
    static std::string Tokyo_Base;

    static std::string London_Forecast;
    static std::string Moscow_Forecast;

    static std::string Tokyo_Forecast_much_warmer;
    static std::string Tokyo_Forecast_warmer;
    static std::string Tokyo_Forecast_same;
    static std::string Tokyo_Forecast_colder;
    static std::string Tokyo_Forecast_much_colder;

    static std::string London_Moscow_difference;
    static std::string Moscow_London_difference;

    static std::string Get_Tokyo_difference_much_warmer;
    static std::string Get_Tokyo_difference_warmer;
    static std::string Get_Tokyo_difference_same;
    static std::string Get_Tokyo_difference_colder;
    static std::string Get_Tokyo_difference_much_colder;
public:
    void SetUp() override;
    void TearDown() override;
};



