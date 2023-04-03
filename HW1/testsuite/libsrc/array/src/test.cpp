#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include "array/array.hpp"
#include <string>

#define MAX 6


TEST_CASE("CheckSize", "[array]")
{
    MyArray<int, MAX> arr = {0, 0, 0, 0, 0, 0};
    CHECK(arr.size() == 6); //size

}

TEST_CASE("CheckFront", "[array]")
{
    MyArray<int, MAX> arr = {0, 0, 0, 0, 0, 0};
    arr.front() = 1;
    CHECK(arr.front() == 1);
}

TEST_CASE("CheckBack", "[array]")
{
    MyArray<int, MAX> arr = {0, 0, 0, 0, 0, 0};
    arr.back() = 6;
    CHECK(arr.back() == 6);
}


TEST_CASE("CheckEmpty", "[array]")
{
    MyArray<int, MAX> arr = {0, 0, 0, 0, 0, 0};
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;
    CHECK_FALSE(arr.empty());


}



TEST_CASE("CheckEquals", "[array]")
{
    MyArray<int, MAX> arr = {0, 0, 0, 0, 0, 0};
    MyArray<int, MAX> arr2 = {0, 0, 0, 0, 0, 0};
    MyArray<int, MAX> arr3 = {0, 0, 0, 0, 0, 0};
    arr.front() = 1;
    arr.back() = 6;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;

    arr2[0] = 1;
    arr2[1] = 2;
    arr2[2] = 3;
    arr2[3] = 4;
    arr2[4] = 5;
    arr2[5] = 6;

    arr3[0] = 6;
    arr3[1] = 5;
    arr3[2] = 4;
    arr3[3] = 3;
    arr3[4] = 2;
    arr3[5] = 1;

    std::cout << arr << std::endl;
    std::cout << arr2 << std::endl;
    bool eq12 = arr == arr2;
    bool neq12 = arr != arr2;
    bool g13 = arr > arr3;
    bool ge13 = arr >= arr3;
    bool s13 = arr < arr3;
    bool se13 = arr <= arr3;
    CHECK(eq12 == 1);
    CHECK(neq12 == 0);
    CHECK(g13 == 0);
    CHECK(ge13 == 0);
    CHECK(s13 == 1);
    CHECK(se13 == 1);

}


