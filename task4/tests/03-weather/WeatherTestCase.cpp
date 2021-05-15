//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"


WeatherMock WeatherTestCase::mock_obj;

std::string WeatherTestCase::London_Base;
std::string WeatherTestCase::Moscow_Base;
std::string WeatherTestCase::Tokyo_Base;

std::string WeatherTestCase::London_Forecast;
std::string WeatherTestCase::Moscow_Forecast;

std::string WeatherTestCase::Tokyo_Forecast_much_warmer;
std::string WeatherTestCase::Tokyo_Forecast_warmer;
std::string WeatherTestCase::Tokyo_Forecast_same;
std::string WeatherTestCase::Tokyo_Forecast_colder;
std::string WeatherTestCase::Tokyo_Forecast_much_colder;

std::string WeatherTestCase::London_Moscow_difference;
std::string WeatherTestCase::Moscow_London_difference;

std::string WeatherTestCase::Get_Tokyo_difference_much_warmer;
std::string WeatherTestCase::Get_Tokyo_difference_warmer;
std::string WeatherTestCase::Get_Tokyo_difference_same;
std::string WeatherTestCase::Get_Tokyo_difference_colder;
std::string WeatherTestCase::Get_Tokyo_difference_much_colder;


void WeatherTestCase::SetUp() {
    London_Base = R"({"main":{"temp":9.24}})";
    Moscow_Base = R"({"main":{"temp":12.02}})";
    Tokyo_Base = R"({"main":{"temp":15.39}})";

    London_Forecast = R"({"list":[{},{},{},{},{},{},{},{"main":{"temp":5.74}}]})";
    Moscow_Forecast = R"({"list":[{},{},{},{},{},{},{},{"main":{"temp":9.99}}]})";

    Tokyo_Forecast_much_warmer = R"({"list":[{},{},{},{},{},{},{},{"main":{"temp":25.05}}]})";
    Tokyo_Forecast_warmer = R"({"list":[{},{},{},{},{},{},{},{"main":{"temp":15.98}}]})";
    Tokyo_Forecast_same = R"({"list":[{},{},{},{},{},{},{},{"main":{"temp":15.45}}]})";
    Tokyo_Forecast_colder = R"({"list":[{},{},{},{},{},{},{},{"main":{"temp":14.74}}]})";
    Tokyo_Forecast_much_colder = R"({"list":[{},{},{},{},{},{},{},{"main":{"temp":5.34}}]})";

    London_Moscow_difference = R"(Weather in London is colder than in Moscow by 2 degrees)";
    Moscow_London_difference = R"(Weather in Moscow is warmer than in London by 2 degrees)";

    Get_Tokyo_difference_much_warmer = R"(The weather in Tokyo tomorrow will be much warmer than today.)";
    Get_Tokyo_difference_warmer = R"(The weather in Tokyo tomorrow will be warmer than today.)";
    Get_Tokyo_difference_same = R"(The weather in Tokyo tomorrow will be the same than today.)";
    Get_Tokyo_difference_colder = R"(The weather in Tokyo tomorrow will be colder than today.)";
    Get_Tokyo_difference_much_colder = R"(The weather in Tokyo tomorrow will be much colder than today.)";
}

void WeatherTestCase::TearDown() {
    London_Base = "";
    Moscow_Base = "";
    London_Forecast = "";
    Moscow_Forecast = "";
    London_Moscow_difference = "";
    Moscow_London_difference = "";
    mock_obj.clear();
}

TEST_F(WeatherTestCase, ExceptionAssertion) {
    mock_obj.SetResponse1(300, London_Base);
    EXPECT_THROW(mock_obj.GetTemperature("London"), std::invalid_argument);
}

TEST_F(WeatherTestCase, GetTemperature) {
    mock_obj.SetResponse1(200, London_Base);
    EXPECT_FLOAT_EQ(mock_obj.GetTemperature("London"), 9.24);
}

TEST_F(WeatherTestCase, GetTomorrowTemperature) {
    mock_obj.SetResponse1(200, London_Forecast);
    EXPECT_FLOAT_EQ(mock_obj.GetTomorrowTemperature("London"), 5.74);
}

TEST_F(WeatherTestCase, FindDiffBetweenTwoCities) {
    mock_obj.SetResponse1(200, London_Base);
    mock_obj.SetResponse2(200, Moscow_Base);
    EXPECT_FLOAT_EQ(mock_obj.FindDiffBetweenTwoCities("London", "Moscow"), -2.78);
}

TEST_F(WeatherTestCase, GetDifferenceString_Colder) {
    mock_obj.SetResponse1(200, London_Base);
    mock_obj.SetResponse2(200, Moscow_Base);
    EXPECT_EQ(mock_obj.GetDifferenceString("London", "Moscow"), London_Moscow_difference);
}

TEST_F(WeatherTestCase, GetDifferenceString_Warmer) {
    mock_obj.SetResponse1(200, Moscow_Base);
    mock_obj.SetResponse2(200, London_Base);
    EXPECT_EQ(mock_obj.GetDifferenceString("Moscow", "London"), Moscow_London_difference);
}

TEST_F(WeatherTestCase, GetTomorrowDiff_MuchWarmer) {
    mock_obj.SetResponse1(200, Tokyo_Forecast_much_warmer);
    mock_obj.SetResponse2(200, Tokyo_Base);
    EXPECT_EQ(mock_obj.GetTomorrowDiff("Tokyo"), Get_Tokyo_difference_much_warmer);
}

TEST_F(WeatherTestCase, GetTomorrowDiff_Warmer) {
    mock_obj.SetResponse1(200, Tokyo_Forecast_warmer);
    mock_obj.SetResponse2(200, Tokyo_Base);
    EXPECT_EQ(mock_obj.GetTomorrowDiff("Tokyo"), Get_Tokyo_difference_warmer);
}

TEST_F(WeatherTestCase, GetTomorrowDiff_Same) {
    mock_obj.SetResponse1(200, Tokyo_Forecast_same);
    mock_obj.SetResponse2(200, Tokyo_Base);
    EXPECT_EQ(mock_obj.GetTomorrowDiff("Tokyo"), Get_Tokyo_difference_same);
}

TEST_F(WeatherTestCase, GetTomorrowDiff_Colder) {
    mock_obj.SetResponse1(200, Tokyo_Forecast_colder);
    mock_obj.SetResponse2(200, Tokyo_Base);
    EXPECT_EQ(mock_obj.GetTomorrowDiff("Tokyo"), Get_Tokyo_difference_colder);
}

TEST_F(WeatherTestCase, GetTomorrowDiff_MuchColder) {
    mock_obj.SetResponse1(200, Tokyo_Forecast_much_colder);
    mock_obj.SetResponse2(200, Tokyo_Base);
    EXPECT_EQ(mock_obj.GetTomorrowDiff("Tokyo"), Get_Tokyo_difference_much_colder);
}

TEST_F(WeatherTestCase, SetApiKey) {
    EXPECT_NO_THROW(mock_obj.SetApiKey("this is new API"));
}