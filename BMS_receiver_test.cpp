#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "BMS_receiver.h"

TEST_CASE("Test to check data array is filled with correct data for given input array")
{
    char BMS_DATA[4][20] = {"Soc: 12, Temp: 25", "Soc: 15, Temp: 28", "Soc: 11, Temp: 32", "Soc: 25, Temp: 18"};
    int data[4];

    GetSocData(BMS_DATA, data, 4);

    REQUIRE(data[0] == 12);
    REQUIRE(data[1] == 15);
    REQUIRE(data[2] == 11);
    REQUIRE(data[3] == 25);
}

TEST_CASE("Test to check temp data array is populated with correct data for given input array")
{
    char BMS_DATA[4][20] = {"Soc: 12, Temp: 25", "Soc: 15, Temp: 28", "Soc: 11, Temp: 32", "Soc: 25, Temp: 18"};
    int tempData[4];

    GetTempData(BMS_DATA, tempData, 4);

    REQUIRE(tempData[0] == 25);
    REQUIRE(tempData[1] == 28);
    REQUIRE(tempData[2] == 32);
    REQUIRE(tempData[3] == 18);
}

TEST_CASE("Test to check min value in array is obtained")
{
    int arr[5] = {16, 8, 48, 17, 0};
    int min = Calculate_Min(arr, 5);

    REQUIRE(min == 0);
}

TEST_CASE("Test to check max value in array is obtained")
{
    int arr[5] = {16, 8, 48, 17, 0};
    int max = Calculate_Max(arr, 5);

    REQUIRE(max == 48);
}

TEST_CASE("Test to check average of values from array")
{
    int arr[5] = {16, 8, 48, 17, 0};
    float avg = Calculate_Average(arr, 1, 5);

    REQUIRE(avg == 14.6f);
}