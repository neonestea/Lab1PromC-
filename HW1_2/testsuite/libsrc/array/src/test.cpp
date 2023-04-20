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


TEST_CASE("CheckIterator", "[array]")
{
    MyArray<int, MAX> arr = {0, 0, 0, 0, 0, 0};
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;
    arr[5] = 6;
    int valueToCheck = 1;
    for (auto it = arr.begin(), end = arr.end(); it != end; ++it) { 
        const auto i = *it; 
        std::cout << i << "\n";
        CHECK(i == valueToCheck);
        valueToCheck++;
    }
}


TEST_CASE("CheckReverseIterator", "[array]")
{
    MyArray<int, MAX> arr = {0, 0, 0, 0, 0, 0};
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;
    arr[5] = 6;
    int valueToCheck = 6;
    for (auto it = arr.rbegin(), end = arr.rend(); it != end; --it) { 
        const auto i = *it; 
        std::cout << i << "\n";
        CHECK(i == valueToCheck);
        valueToCheck--;
    }

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

