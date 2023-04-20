
#include <iostream>
#include <stdexcept>
#include "array/array.hpp"


#define MAX 6



int main()
{
    
    //int arraysCount = 0;
    MyArray<int, MAX> arr1 = {0, 0, 0, 0, 0, 0};
    MyArray<int, MAX> arr2 = {1, 2, 3, 4, 5, 6};
    MyArray<int, MAX> arr3 = {1, 2, 3, 4, 5, 6};;
    MyArray<int, MAX> arr4 = {6, 5, 4, 3, 2, 1};;
    MyArray<int, MAX> arr5  = {0, 0, 0, 0, 0, 0};
    while(true)
    {
        std::cout << "1.  Change element" << std::endl;
        std::cout << "2.  Arr1 == Arr2" << std::endl;
        std::cout << "3.  Arr1 != Arr2" << std::endl;
        std::cout << "4.  Arr1 >= Arr2" << std::endl;
        std::cout << "5.  Arr1 <= Arr2" << std::endl;
        std::cout << "6.  Arr1 > Arr2" << std::endl;
        std::cout << "7.  Arr1 < Arr2" << std::endl;
        std::cout << "8.  Print array element" << std::endl;
        std::cout << "9.  Check if array is empty" << std::endl;
        std::cout << "10. Print array size" << std::endl;
        std::cout << "11. Print front" << std::endl;
        std::cout << "12. Print back" << std::endl;
        std::cout << "13. Print Array" << std::endl;
        std::cout << "14. Create Array (Not supported)" << std::endl;
        std::cout << "15. Exit" << std::endl;
        std::cout << "Enter command number: " << std::endl;
        int x;
        std::cin >> x;
        int option;
        int arrayNumber;
        int position;
        switch(x)
        {
            case 1:
                std::cout << "Enter array number: " << std::endl;
                std::cin >> arrayNumber;
                std::cout << "Enter position: " << std::endl;
               
                std::cin >> position;
                std::cout << "Enter new value: " << std::endl;
                int newValue;
                std::cin >> newValue;
                if (arrayNumber == 1)
                {
                    arr1[position] = newValue;
                }
                else if (arrayNumber == 2)
                {
                    arr2[position] = newValue;
                }
                else if (arrayNumber == 3)
                {
                    arr3[position] = newValue;
                }
                else if (arrayNumber == 4)
                {
                    arr4[position] = newValue;
                }
                else if (arrayNumber == 5)
                {
                    arr5[position] = newValue;
                }
                else 
                {
                    std::cout << "Maximum array number is 5!";
                    continue;
                }


                continue;
            case 2:
                std::cout << "Enter 1 to compare Array 1 and Array 2: " << std::endl;
                std::cout << "Enter 2 to compare Array 1 and Array 3: " << std::endl;
                std::cout << "Enter 3 to compare Array 1 and Array 4: " << std::endl;
                std::cout << "Enter 4 to compare Array 1 and Array 5: " << std::endl;
                std::cout << "Enter 5 to compare Array 2 and Array 3: " << std::endl;
                std::cout << "Enter 6 to compare Array 2 and Array 4: " << std::endl;
                std::cout << "Enter 7 to compare Array 2 and Array 5: " << std::endl;
                std::cout << "Enter 8 to compare Array 3 and Array 4: " << std::endl;
                std::cout << "Enter 9 to compare Array 3 and Array 5: " << std::endl;
                std::cout << "Enter 10 to compare Array 4 and Array 5: " << std::endl;
                
                std::cin >> option;
                if (option == 1)
                {
                    bool res = arr1 == arr2;
                    if (res == 1)
                    {
                        std::cout << "Equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not equal" << std::endl;
                    }
                }
                else if (option == 2)
                {
                    bool res = arr1 == arr3;
                    if (res == 1)
                    {
                        std::cout << "Equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not equal" << std::endl;
                    }
                }
                else if (option == 3)
                {
                    bool res = arr1 == arr4;
                    if (res == 1)
                    {
                        std::cout << "Equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not equal" << std::endl;
                    }
                }
                else if (option == 4)
                {
                    bool res = arr1 == arr5;
                    if (res == 1)
                    {
                        std::cout << "Equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not equal" << std::endl;
                    }
                }
                else if (option == 5)
                {
                    bool res = arr2 == arr3;
                    if (res == 1)
                    {
                        std::cout << "Equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not equal" << std::endl;
                    }
                }
                else if (option == 6)
                {
                    bool res = arr2 == arr4;
                    if (res == 1)
                    {
                        std::cout << "Equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not equal" << std::endl;
                    }
                }
                else if (option == 7)
                {
                    bool res = arr2 == arr5;
                    if (res == 1)
                    {
                        std::cout << "Equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not equal" << std::endl;
                    }
                }
                else if (option == 8)
                {
                    bool res = arr3 == arr4;
                    if (res == 1)
                    {
                        std::cout << "Equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not equal" << std::endl;
                    }
                }
                else if (option == 9)
                {
                    bool res = arr3 == arr5;
                    if (res == 1)
                    {
                        std::cout << "Equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not equal" << std::endl;
                    }
                }
                else if (option == 10)
                {
                    bool res = arr4 == arr5;
                    if (res == 1)
                    {
                        std::cout << "Equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not equal" << std::endl;
                    }
                }
                else 
                {
                    std::cout << "Incorrect option!";
                    continue;
                }
                continue;
            case 3:
                std::cout << "Enter 1 to compare Array 1 and Array 2: " << std::endl;
                std::cout << "Enter 2 to compare Array 1 and Array 3: " << std::endl;
                std::cout << "Enter 3 to compare Array 1 and Array 4: " << std::endl;
                std::cout << "Enter 4 to compare Array 1 and Array 5: " << std::endl;
                std::cout << "Enter 5 to compare Array 2 and Array 3: " << std::endl;
                std::cout << "Enter 6 to compare Array 2 and Array 4: " << std::endl;
                std::cout << "Enter 7 to compare Array 2 and Array 5: " << std::endl;
                std::cout << "Enter 8 to compare Array 3 and Array 4: " << std::endl;
                std::cout << "Enter 9 to compare Array 3 and Array 5: " << std::endl;
                std::cout << "Enter 10 to compare Array 4 and Array 5: " << std::endl;
                std::cin >> option;
                if (option == 1)
                {
                    bool res = arr1 != arr2;
                    if (res != 1)
                    {
                        std::cout << "Equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not equal" << std::endl;
                    }
                }
                else if (option == 2)
                {
                    bool res = arr1 != arr3;
                    if (res != 1)
                    {
                        std::cout << "Equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not equal" << std::endl;
                    }
                }
                else if (option == 3)
                {
                    bool res = arr1 != arr4;
                    if (res != 1)
                    {
                        std::cout << "Equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not equal" << std::endl;
                    }
                }
                else if (option == 4)
                {
                    bool res = arr1 != arr5;
                    if (res != 1)
                    {
                        std::cout << "Equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not equal" << std::endl;
                    }
                }
                else if (option == 5)
                {
                    bool res = arr2 != arr3;
                    if (res != 1)
                    {
                        std::cout << "Equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not equal" << std::endl;
                    }
                }
                else if (option == 6)
                {
                    bool res = arr2 != arr4;
                    if (res != 1)
                    {
                        std::cout << "Equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not equal" << std::endl;
                    }
                }
                else if (option == 7)
                {
                    bool res = arr2 != arr5;
                    if (res != 1)
                    {
                        std::cout << "Equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not equal" << std::endl;
                    }
                }
                else if (option == 8)
                {
                    bool res = arr3 != arr4;
                    if (res != 1)
                    {
                        std::cout << "Equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not equal" << std::endl;
                    }
                }
                else if (option == 9)
                {
                    bool res = arr3 != arr5;
                    if (res != 1)
                    {
                        std::cout << "Equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not equal" << std::endl;
                    }
                }
                else if (option == 10)
                {
                    bool res = arr4 != arr5;
                    if (res != 1)
                    {
                        std::cout << "Equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not equal" << std::endl;
                    }
                }
                else 
                {
                    std::cout << "Incorrect option!";
                    continue;
                }
                continue;
            case 4:
                std::cout << "Enter 1 to compare Array 1 and Array 2: " << std::endl;
                std::cout << "Enter 2 to compare Array 1 and Array 3: " << std::endl;
                std::cout << "Enter 3 to compare Array 1 and Array 4: " << std::endl;
                std::cout << "Enter 4 to compare Array 1 and Array 5: " << std::endl;
                std::cout << "Enter 5 to compare Array 2 and Array 3: " << std::endl;
                std::cout << "Enter 6 to compare Array 2 and Array 4: " << std::endl;
                std::cout << "Enter 7 to compare Array 2 and Array 5: " << std::endl;
                std::cout << "Enter 8 to compare Array 3 and Array 4: " << std::endl;
                std::cout << "Enter 9 to compare Array 3 and Array 5: " << std::endl;
                std::cout << "Enter 10 to compare Array 4 and Array 5: " << std::endl;
                std::cin >> option;
                if (option == 1)
                {
                    bool res = arr1 >= arr2;
                    if (res == 1)
                    {
                        std::cout << "Greater or equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not greater or equal" << std::endl;
                    }
                }
                else if (option == 2)
                {
                    bool res = arr1 >= arr3;
                    if (res == 1)
                    {
                        std::cout << "Greater or equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not greater or equal" << std::endl;
                    }
                }
                else if (option == 3)
                {
                    bool res = arr1 >= arr4;
                    if (res == 1)
                    {
                        std::cout << "Greater or equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not greater or equal" << std::endl;
                    }
                }
                else if (option == 4)
                {
                    bool res = arr1 >= arr5;
                    if (res == 1)
                    {
                        std::cout << "Greater or equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not greater or equal" << std::endl;
                    }
                }
                else if (option == 5)
                {
                    bool res = arr2 >= arr3;
                    if (res == 1)
                    {
                        std::cout << "Greater or equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not greater or equal" << std::endl;
                    }
                }
                else if (option == 6)
                {
                    bool res = arr2 >= arr4;
                    if (res == 1)
                    {
                        std::cout << "Greater or equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not greater or equal" << std::endl;
                    }
                }
                else if (option == 7)
                {
                    bool res = arr2 >= arr5;
                    if (res == 1)
                    {
                        std::cout << "Greater or equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not greater or equal" << std::endl;
                    }
                }
                else if (option == 8)
                {
                    bool res = arr3 >= arr4;
                    if (res == 1)
                    {
                        std::cout << "Greater or equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not greater or equal" << std::endl;
                    }
                }
                else if (option == 9)
                {
                    bool res = arr3 >= arr5;
                    if (res == 1)
                    {
                        std::cout << "Greater or equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not greater or equal" << std::endl;
                    }
                }
                else if (option == 10)
                {
                    bool res = arr4 >= arr5;
                    if (res == 1)
                    {
                        std::cout << "Greater or equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not greater or equal" << std::endl;
                    }
                }
                else 
                {
                    std::cout << "Incorrect option!";
                    continue;
                }
                continue;
            case 5:
                std::cout << "Enter 1 to compare Array 1 and Array 2: " << std::endl;
                std::cout << "Enter 2 to compare Array 1 and Array 3: " << std::endl;
                std::cout << "Enter 3 to compare Array 1 and Array 4: " << std::endl;
                std::cout << "Enter 4 to compare Array 1 and Array 5: " << std::endl;
                std::cout << "Enter 5 to compare Array 2 and Array 3: " << std::endl;
                std::cout << "Enter 6 to compare Array 2 and Array 4: " << std::endl;
                std::cout << "Enter 7 to compare Array 2 and Array 5: " << std::endl;
                std::cout << "Enter 8 to compare Array 3 and Array 4: " << std::endl;
                std::cout << "Enter 9 to compare Array 3 and Array 5: " << std::endl;
                std::cout << "Enter 10 to compare Array 4 and Array 5: " << std::endl;

                std::cin >> option;
                if (option == 1)
                {
                    bool res = arr1 <= arr2;
                    if (res == 1)
                    {
                        std::cout << "Smaller or equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not smaller or equal" << std::endl;
                    }
                }
                else if (option == 2)
                {
                    bool res = arr1 <= arr3;
                    if (res == 1)
                    {
                        std::cout << "Smaller or equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not smaller or equal" << std::endl;
                    }
                }
                else if (option == 3)
                {
                    bool res = arr1 <= arr4;
                    if (res == 1)
                    {
                        std::cout << "Smaller or equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not smaller or equal" << std::endl;
                    }
                }
                else if (option == 4)
                {
                    bool res = arr1 <= arr5;
                    if (res == 1)
                    {
                        std::cout << "Smaller or equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not smaller or equal" << std::endl;
                    }
                }
                else if (option == 5)
                {
                    bool res = arr2 <= arr3;
                    if (res == 1)
                    {
                        std::cout << "Smaller or equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not smaller or equal" << std::endl;
                    }
                }
                else if (option == 6)
                {
                    bool res = arr2 <= arr4;
                    if (res == 1)
                    {
                        std::cout << "Smaller or equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not smaller or equal" << std::endl;
                    }
                }
                else if (option == 7)
                {
                    bool res = arr2 <= arr5;
                    if (res == 1)
                    {
                        std::cout << "Smaller or equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not smaller or equal" << std::endl;
                    }
                }
                else if (option == 8)
                {
                    bool res = arr3 <= arr4;
                    if (res == 1)
                    {
                        std::cout << "Smaller or equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not smaller or equal" << std::endl;
                    }
                }
                else if (option == 9)
                {
                    bool res = arr3 <= arr5;
                    if (res == 1)
                    {
                        std::cout << "Smaller or equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not smaller or equal" << std::endl;
                    }
                }
                else if (option == 10)
                {
                    bool res = arr4 <= arr5;
                    if (res == 1)
                    {
                        std::cout << "Smaller or equal" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not smaller or equal" << std::endl;
                    }
                }
                else 
                {
                    std::cout << "Incorrect option!";
                    continue;
                }
                continue;
            case 6:
                std::cout << "Enter 1 to compare Array 1 and Array 2: " << std::endl;
                std::cout << "Enter 2 to compare Array 1 and Array 3: " << std::endl;
                std::cout << "Enter 3 to compare Array 1 and Array 4: " << std::endl;
                std::cout << "Enter 4 to compare Array 1 and Array 5: " << std::endl;
                std::cout << "Enter 5 to compare Array 2 and Array 3: " << std::endl;
                std::cout << "Enter 6 to compare Array 2 and Array 4: " << std::endl;
                std::cout << "Enter 7 to compare Array 2 and Array 5: " << std::endl;
                std::cout << "Enter 8 to compare Array 3 and Array 4: " << std::endl;
                std::cout << "Enter 9 to compare Array 3 and Array 5: " << std::endl;
                std::cout << "Enter 10 to compare Array 4 and Array 5: " << std::endl;

                std::cin >> option;
                if (option == 1)
                {
                    bool res = arr1 >= arr2;
                    if (res == 1)
                    {
                        std::cout << "Greater" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not greater" << std::endl;
                    }
                }
                else if (option == 2)
                {
                    bool res = arr1 > arr3;
                    if (res == 1)
                    {
                        std::cout << "Greater" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not greater" << std::endl;
                    }
                }
                else if (option == 3)
                {
                    bool res = arr1 > arr4;
                    if (res == 1)
                    {
                        std::cout << "Greater" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not greater" << std::endl;
                    }
                }
                else if (option == 4)
                {
                    bool res = arr1 > arr5;
                    if (res == 1)
                    {
                        std::cout << "Greater" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not greater" << std::endl;
                    }
                }
                else if (option == 5)
                {
                    bool res = arr2 > arr3;
                    if (res == 1)
                    {
                        std::cout << "Greater" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not greater" << std::endl;
                    }
                }
                else if (option == 6)
                {
                    bool res = arr2 > arr4;
                    if (res == 1)
                    {
                        std::cout << "Greater" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not greater" << std::endl;
                    }
                }
                else if (option == 7)
                {
                    bool res = arr2 > arr5;
                    if (res == 1)
                    {
                        std::cout << "Greater" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not greater" << std::endl;
                    }
                }
                else if (option == 8)
                {
                    bool res = arr3 > arr4;
                    if (res == 1)
                    {
                        std::cout << "Greater" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not greater" << std::endl;
                    }
                }
                else if (option == 9)
                {
                    bool res = arr3 > arr5;
                    if (res == 1)
                    {
                        std::cout << "Greater" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not greater" << std::endl;
                    }
                }
                else if (option == 10)
                {
                    bool res = arr4 > arr5;
                    if (res == 1)
                    {
                        std::cout << "Greater" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not greater" << std::endl;
                    }
                }
                else 
                {
                    std::cout << "Incorrect option!";
                    continue;
                }
                continue;
            case 7:
                std::cout << "Enter 1 to compare Array 1 and Array 2: " << std::endl;
                std::cout << "Enter 2 to compare Array 1 and Array 3: " << std::endl;
                std::cout << "Enter 3 to compare Array 1 and Array 4: " << std::endl;
                std::cout << "Enter 4 to compare Array 1 and Array 5: " << std::endl;
                std::cout << "Enter 5 to compare Array 2 and Array 3: " << std::endl;
                std::cout << "Enter 6 to compare Array 2 and Array 4: " << std::endl;
                std::cout << "Enter 7 to compare Array 2 and Array 5: " << std::endl;
                std::cout << "Enter 8 to compare Array 3 and Array 4: " << std::endl;
                std::cout << "Enter 9 to compare Array 3 and Array 5: " << std::endl;
                std::cout << "Enter 10 to compare Array 4 and Array 5: " << std::endl;

                std::cin >> option;
                if (option == 1)
                {
                    bool res = arr1 < arr2;
                    if (res == 1)
                    {
                        std::cout << "Smaller" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not smaller" << std::endl;
                    }
                }
                else if (option == 2)
                {
                    bool res = arr1 < arr3;
                    if (res == 1)
                    {
                        std::cout << "Smaller" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not smaller" << std::endl;
                    }
                }
                else if (option == 3)
                {
                    bool res = arr1 < arr4;
                    if (res == 1)
                    {
                        std::cout << "Smaller" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not smaller" << std::endl;
                    }
                }
                else if (option == 4)
                {
                    bool res = arr1 < arr5;
                    if (res == 1)
                    {
                        std::cout << "Smaller" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not smaller" << std::endl;
                    }
                }
                else if (option == 5)
                {
                    bool res = arr2 < arr3;
                    if (res == 1)
                    {
                        std::cout << "Smaller" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not smaller" << std::endl;
                    }
                }
                else if (option == 6)
                {
                    bool res = arr2 < arr4;
                    if (res == 1)
                    {
                        std::cout << "Smaller" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not smaller" << std::endl;
                    }
                }
                else if (option == 7)
                {
                    bool res = arr2 < arr5;
                    if (res == 1)
                    {
                        std::cout << "Smaller" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not smaller" << std::endl;
                    }
                }
                else if (option == 8)
                {
                    bool res = arr3 < arr4;
                    if (res == 1)
                    {
                        std::cout << "Smaller" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not smaller" << std::endl;
                    }
                }
                else if (option == 9)
                {
                    bool res = arr3 < arr5;
                    if (res == 1)
                    {
                        std::cout << "Smaller" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not smaller" << std::endl;
                    }
                }
                else if (option == 10)
                {
                    bool res = arr4 < arr5;
                    if (res == 1)
                    {
                        std::cout << "Smaller" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Not smaller" << std::endl;
                    }
                }
                else 
                {
                    std::cout << "Incorrect option!";
                    continue;
                }
                continue;
            case 8:
                std::cout << "Enter array number: " << std::endl;
                
                std::cin >> arrayNumber;
                std::cout << "Enter position: " << std::endl;
                
                std::cin >> position;
                if (arrayNumber == 1)
                {
                    std::cout << arr1[position] <<std::endl;
                }
                else if (arrayNumber == 2)
                {
                    std::cout << arr2[position] <<std::endl;
                }
                else if (arrayNumber == 3)
                {
                    std::cout << arr3[position] <<std::endl;
                }
                else if (arrayNumber == 4)
                {
                    std::cout << arr4[position] <<std::endl;
                }
                else if (arrayNumber == 5)
                {
                    std::cout << arr5[position] <<std::endl;
                }
                else 
                {
                    std::cout << "Maximum array number is 5!";
                    continue;
                }


                continue;
            case 9:
                std::cout << "Enter array number: " << std::endl;

                std::cin >> arrayNumber;
                if (arrayNumber == 1)
                {
                    std::cout << arr1.empty() <<std::endl;
                }
                else if (arrayNumber == 2)
                {
                    std::cout << arr2.empty() <<std::endl;
                }
                else if (arrayNumber == 3)
                {
                    std::cout << arr3.empty() <<std::endl;
                }
                else if (arrayNumber == 4)
                {
                    std::cout << arr4.empty() <<std::endl;
                }
                else if (arrayNumber == 5)
                {
                    std::cout << arr5.empty() <<std::endl;
                }
                else 
                {
                    std::cout << "Maximum array number is 5!";
                    continue;
                }


                continue;
            case 10:
                std::cout << "Enter array number: " << std::endl;

                std::cin >> arrayNumber;
                if (arrayNumber == 1)
                {
                    std::cout << arr1.size() <<std::endl;
                }
                else if (arrayNumber == 2)
                {
                    std::cout << arr2.size() <<std::endl;
                }
                else if (arrayNumber == 3)
                {
                    std::cout << arr3.size() <<std::endl;
                }
                else if (arrayNumber == 4)
                {
                    std::cout << arr4.size() <<std::endl;
                }
                else if (arrayNumber == 5)
                {
                    std::cout << arr5.size() <<std::endl;
                }
                else 
                {
                    std::cout << "Maximum array number is 5!";
                    continue;
                }


                continue;
            case 11:
                std::cout << "Enter array number: " << std::endl;

                std::cin >> arrayNumber;
                if (arrayNumber == 1)
                {
                    std::cout << arr1.front() <<std::endl;
                }
                else if (arrayNumber == 2)
                {
                    std::cout << arr2.front() <<std::endl;
                }
                else if (arrayNumber == 3)
                {
                    std::cout << arr3.front() <<std::endl;
                }
                else if (arrayNumber == 4)
                {
                    std::cout << arr4.front() <<std::endl;
                }
                else if (arrayNumber == 5)
                {
                    std::cout << arr5.front() <<std::endl;
                }
                else 
                {
                    std::cout << "Maximum array number is 5!";
                    continue;
                }


                continue;
            case 12:
                std::cout << "Enter array number: " << std::endl;

                std::cin >> arrayNumber;
                if (arrayNumber == 1)
                {
                    std::cout << arr1.back() <<std::endl;
                }
                else if (arrayNumber == 2)
                {
                    std::cout << arr2.back() <<std::endl;
                }
                else if (arrayNumber == 3)
                {
                    std::cout << arr3.back() <<std::endl;
                }
                else if (arrayNumber == 4)
                {
                    std::cout << arr4.back() <<std::endl;
                }
                else if (arrayNumber == 5)
                {
                    std::cout << arr5.back() <<std::endl;
                }
                else 
                {
                    std::cout << "Maximum array number is 5!";
                    continue;
                }


                continue;
            case 13:
                std::cout << "Enter array number: " << std::endl;

                std::cin >> arrayNumber;
                if (arrayNumber == 1)
                {
                    std::cout << arr1 <<std::endl;
                }
                else if (arrayNumber == 2)
                {
                    std::cout << arr2 <<std::endl;
                }
                else if (arrayNumber == 3)
                {
                    std::cout << arr3 <<std::endl;
                }
                else if (arrayNumber == 4)
                {
                    std::cout << arr4 <<std::endl;
                }
                else if (arrayNumber == 5)
                {
                    std::cout << arr5 <<std::endl;
                }
                else 
                {
                    std::cout << "Maximum array number is 5!";
                    continue;
                }


                continue;
            case 14:
                /*std::cout << "Enter array size:" << std::endl;
                size_t n;
                std::cin >> n;
                if (arraysCount == 0)
                {
                    MyArray<int, n> arr1;
                    arraysCount++;
                }
                else if (arraysCount == 1)
                {
                    MyArray<int, n> arr2;
                    arraysCount++;
                }
                else if (arraysCount == 2)
                {
                    MyArray<int, n> arr3;
                    arraysCount++;
                }
                else if (arraysCount == 3)
                {
                    MyArray<int, n> arr4;
                    arraysCount++;
                }
                else if (arraysCount == 4)
                {
                    MyArray<int, n> arr5;
                    arraysCount++;
                }
                else
                {
                    std::cout << "Maximum arrays count is 5!";
                    continue;
                }*/
                
                
                continue;
            case 15:
                return 0;
            default:
                std::cout << "Incorrect number!" << std::endl;
                continue;
        }
        
    }
    
    return 0;
}



