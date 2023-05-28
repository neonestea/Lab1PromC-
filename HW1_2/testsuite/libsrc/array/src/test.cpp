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

TEST_CASE("CheckRandomAccess", "[array]")
{
    MyArray<int, MAX> arr = {1, 2, 3, 4, 5, 6};
    CHECK(arr[0] == 1);
    CHECK(arr[1] == 2);
    CHECK(arr[2] == 3);
    CHECK(arr[3] == 4);
    CHECK(arr[4] == 5);
    CHECK(arr[5] == 6);

}

TEST_CASE("CheckFront", "[array]")
{
    MyArray<int, MAX> arr = {0, 0, 0, 0, 0, 0};
    arr.front() = 1;
    CHECK(arr.front() == 1);
    //arr.frontConst() = 14; ошибка компиляции, правильно
    CHECK(arr.front() == 1);
    CHECK(arr.frontConst() == 1);
}

TEST_CASE("CheckBack", "[array]")
{
    MyArray<int, MAX> arr = {0, 0, 0, 0, 0, 0};
    arr.back() = 1;
    CHECK(arr.back() == 1);
    //arr.backConst() = 100;  ошибка компиляции, правильно
    CHECK(arr.backConst() == 1);
    CHECK(arr.back() == 1);
}

TEST_CASE("CheckAt", "[array]")
{
    MyArray<int, MAX> arr = {0, 0};
    CHECK_THROWS_AS(arr.at(98), std::invalid_argument);
    arr[0] = 3;
    CHECK(arr.at(0) == 3);

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


TEST_CASE("CheckIterator", "[array]")
{
    MyArray<int, MAX> arr = {0, 0, 0, 0, 0, 0};
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;
    arr[5] = 6;


    int valueToCheck = 6;
    //std::cout << *arr.end();
    //std::cout << *arr.begin();
    for (auto it = --arr.end(), end = arr.begin(); it != end; --it) {
        const auto i = *it;
    
        CHECK(i == valueToCheck);
        valueToCheck--;
    }

    valueToCheck = 1;
    for (auto it = arr.begin(), end = arr.end(); it != end; ++it) { 
        
        auto i = *it; 
        CHECK(i == valueToCheck);
        valueToCheck++;
    }
    *arr.begin() = 100;
    *arr.end() = 200;
    CHECK(*arr.begin() == 100);
    CHECK(*arr.end() == 200);

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
    
    for (auto it = arr.rbegin(), end = arr.rend(); it != end; ++it) { 
        auto i = *it; 
        std::cout << "Is " << i << " should be " << valueToCheck << "\n";
        
        CHECK(i == valueToCheck);
        valueToCheck--;
    }
    valueToCheck = 1;
   
    for (auto it = arr.rend(), end = arr.rbegin(); it != end; --it) {
        const auto i = *it;
        std::cout << "Is " << i << " should be " << valueToCheck << "\n";
        CHECK(i == valueToCheck);
        valueToCheck++;
    }
    *arr.rbegin() = 100;
    *arr.rend() = 200;
    CHECK(*arr.rbegin() == 100);
    CHECK(*arr.rend() == 200);

}

TEST_CASE("CheckConstIterator", "[array]")
{
    MyArray<int, MAX> arr = {0, 0, 0, 0, 0, 0};
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;
    arr[5] = 6;

    std::cout << arr << "\n";
    int valueToCheck = 1;
    for (auto it = arr.begin(), end = arr.end(); it != end; ++it) { 
        auto i = *it; 
        std::cout << i << "\n";
        CHECK(i == valueToCheck);
        valueToCheck++;
    }
   
}


TEST_CASE("CheckConstReverseIterator", "[array]")
{
    MyArray<int, MAX> arr = {0, 0, 0, 0, 0, 0};
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;
    arr[5] = 6;
    int valueToCheck = 6;
    for (auto it = arr.rbegin(), end = arr.rend(); it != end; ++it) { 
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

