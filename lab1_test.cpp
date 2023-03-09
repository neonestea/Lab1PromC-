#include <gtest/gtest.h>
#include <iostream>
#include "lab1.hpp"
#include <string>

#define MAX 6

class TestFoo : public ::testing::Test
{
    protected: 
        void SetUp() {}
        void TearDown() {}
};

TEST(TestUtils, my_test) //Правильный случай, для примера взят массив int
{
    MyArray<int, MAX> arr = {0, 0, 0, 0, 0, 0};
    MyArray<int, MAX> arr2 = {0, 0, 0, 0, 0, 0};
    MyArray<int, MAX> arr3 = {0, 0, 0, 0, 0, 0};
    ASSERT_EQ(arr.size(), 6); //size
    arr.front() = 1;
    ASSERT_EQ(arr.front(), 1);
    arr.back() = 6;
    ASSERT_EQ(arr.back(), 6);
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;
    int valueToCheck = 1;
    for (auto it = arr.begin(), end = arr.end(); it != end; ++it) { 
        const auto i = *it; 
        std::cout << i << "\n";
        ASSERT_EQ(i, valueToCheck);
        valueToCheck++;
    }
    valueToCheck--;
    for (auto it = arr.rbegin(), end = arr.rend(); it != end; --it) { 
        const auto i = *it; 
        std::cout << i << "\n";
        ASSERT_EQ(i, valueToCheck);
        valueToCheck--;
    }
    EXPECT_THROW({
        try
        {
            
            arr.at(98);
        }
        catch( const std::invalid_argument& e )
        {
            
            EXPECT_STREQ( "Element not exist", e.what() );
            throw;
        }
    }, std::invalid_argument );
    ASSERT_EQ(arr.empty(), 0);

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
    ASSERT_EQ(eq12, 1);
    ASSERT_EQ(neq12, 0);
    ASSERT_EQ(g13, 0);
    ASSERT_EQ(ge13, 0);
    ASSERT_EQ(s13, 1);
    ASSERT_EQ(se13, 1);

}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}