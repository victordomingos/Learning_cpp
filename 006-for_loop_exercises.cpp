// exercises.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    // list numbers from 2 to 5 (including 2 and 5)
    for (size_t i = 2; i <= 5; i++)
    {
        cout << i << " ";
    }
    cout << "\n\n";
    
    // list numbers from 100 to 110
    for (size_t i = 100; i <= 110; i++)
    {
        cout << i << " ";
    }
    cout << "\n\n";


    // list numbers from 100 to 110
    for (size_t i = 10; i <= 1000; i += 10)
    {
        cout << i << " ";
    }
    cout << "\n\n";


    // list even numbers up to 100
    for (size_t i = 0; i <= 100; i += 2)
    {
        cout << i << " ";
    }
    cout << "\n\n";


    // list odd numbers up to 100
    for (size_t i = 1; i <= 100; i += 2)
    {
        cout << i << " ";
    }
    cout << "\n\n";



    // ask the user 2 numbers and list all integers between them
    int low, high, temp;

    cout << "\nPlease enter the lower number:  ";    cin >> low;
    cout << "\nPlease enter the higher number: ";    cin >> high;

    if (low > high)
    {
        cout << "\n\nPlease follow the instructions. I first said lower, then higher!";
        cout << "\nBut the computer is you friend. Let's swap the numbers automatically for you:";
        cout << "\nYou entered: " << low << " - " << high;
        cout << "\nWe'll be using instead: " << high << " - " << low;
        temp = low;
        low = high;
        high = temp;
    }

    cout << "\n\nThese are all the integers between them, including your special numbers:\n";

    for (int i = low; i <= high; i += 1)
    {
        cout << i << " ";
    }
    cout << "\n\n";
}
