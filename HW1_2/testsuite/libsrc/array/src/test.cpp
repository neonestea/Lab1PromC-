#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include "array/array.hpp"
#include <string>

#define MAX 6

void createArray() {
    MyArray<int, MAX> arr({0, 0, 0, 0, 0, 0, 5, 54});
}
TEST_CASE("CheckSize", "[array]")
{
    
    
    CHECK_THROWS_AS(createArray(), std::invalid_argument);
    
}

TEST_CASE("CheckInitialization", "[array]")
{
    MyArray<int, MAX> arr({0, 0, 0, 0, 0, 0});
    CHECK(arr.size() == 6); //size

}

TEST_CASE("CheckRandomAccess", "[array]")
{
    MyArray<int, MAX> arr({1, 2, 3, 4, 5, 6});
     for (int i = 0; i < MAX; ++i) {
         CHECK(arr[i] == i + 1);
    }

}

TEST_CASE("CheckFront", "[array]")
{
    MyArray<int, MAX> arr({0, 0, 0, 0, 0, 0});
    arr.front() = 1;
    CHECK(arr.front() == 1);
    //arr.frontConst() = 14; ошибка компиляции, правильно
    CHECK(arr.front() == 1);
    CHECK(arr.frontConst() == 1);
}

TEST_CASE("CheckBack", "[array]")
{
    MyArray<int, MAX> arr({0, 0, 0, 0, 0, 0});
    arr.back() = 1;
    CHECK(arr.back() == 1);
    //arr.backConst() = 100;  ошибка компиляции, правильно
    CHECK(arr.backConst() == 1);
    CHECK(arr.back() == 1);
}

TEST_CASE("CheckAt", "[array]")
{
    MyArray<int, 2> arr({0, 0});
    CHECK_THROWS_AS(arr.at(98), std::invalid_argument);
    arr[0] = 3;
    CHECK(arr.at(0) == 3);

}

TEST_CASE("CheckEquals", "[array]")
{
    MyArray<int, MAX> arr({0, 0, 0, 0, 0, 0});
    MyArray<int, MAX> arr2({0, 0, 0, 0, 0, 0});
    MyArray<int, MAX> arr3({0, 0, 0, 0, 0, 0});
    arr.front() = 1;
    arr.back() = 6;

    for (int i = 0; i < MAX; ++i) {
        if (i != 0 && i != MAX) {
            arr[i] = i + 1;
        }
        arr2[i] = i + 1;
        arr3[i] = MAX - i;
    }
    std::cout << arr << std::endl;
    std::cout << arr2 << std::endl;
    std::cout << arr3 << std::endl;

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
    MyArray<int, MAX> arr({0, 0, 0, 0, 0, 0});
    for (int i = 0; i < MAX; ++i) {
        
        arr[i] = i + 1;
    }


    int valueToCheck = 6;
    for (auto it = arr.end(), end = arr.begin(); it != end; --it) {
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
    MyArray<int, MAX> arr({0, 0, 0, 0, 0, 0});
    for (int i = 0; i < MAX; ++i) {
        
        arr[i] = i + 1;
    }
    int valueToCheck = 6;
    
    for (auto it = arr.rbegin(), end = arr.rend(); it != end; ++it) { 
        auto i = *it; 
        
        CHECK(i == valueToCheck);
        valueToCheck--;
    }
    valueToCheck = 1;
   
    for (auto it = arr.rend(), end = arr.rbegin(); it != end; --it) {
        const auto i = *it;
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
    MyArray<int, MAX> arr({0, 0, 0, 0, 0, 0});
    for (int i = 0; i < MAX; ++i) {
        
        arr[i] = i + 1;
    }

    int valueToCheck = 1;
    for (auto it = arr.begin(), end = arr.end(); it != end; ++it) { 
        auto i = *it; 
        CHECK(i == valueToCheck);
        valueToCheck++;
    }
   
}


TEST_CASE("CheckConstReverseIterator", "[array]")
{
    MyArray<int, MAX> arr({0, 0, 0, 0, 0, 0});
    for (int i = 0; i < MAX; ++i) {
        
        arr[i] = i + 1;
    }
    int valueToCheck = 6;
    for (auto it = arr.rbegin(), end = arr.rend(); it != end; ++it) { 
        const auto i = *it; 
        CHECK(i == valueToCheck);
        valueToCheck--;
    }
   

}




TEST_CASE("CheckEmpty", "[array]")
{
    MyArray<int, MAX> arr({0, 0, 0, 0, 0, 0});
    for (int i = 0; i < MAX; ++i) {
        
        arr[i] = i;
    }
    CHECK_FALSE(arr.empty());


}

