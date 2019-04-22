// Exercises_for_loop.cpp : A few basic exercises on the for loop.
// 2019-04-16
// Victor Domingos
#include <iostream>
using namespace std;

int main()
{
    // 1) list numbers 1 to 10 in the same line
    for (size_t i = 1; i <= 10; i++)
    {
        cout << i << " ";
    }
    cout << endl << endl;


    // 2) list numbers 1 to 10 in the same line, separated by dash
    for (size_t i = 1; i <= 10; i++)
    {
        cout << i;
        if (i != 10) {
            cout << "-";
        }
    }
    cout << endl << endl;


    // 3) list numbers 1 to 10 in separate lines
    for (size_t i = 1; i <= 10; i++)
    {
        cout << i << endl;
    }
    cout << endl << endl;



    // 4) list numbers 1 to 10, inserting a blank line between them
    for (size_t i = 1; i <= 10; i++)
    {
        cout << i << endl << endl;
    }
    cout << endl << endl;


    // 5) list all odd numbers from 1 to 20
    for (size_t i = 1; i < 20; i+=2)
    {
        cout << i << " "; 
    }
    cout << endl << endl;


    // 6) list all odd numbers from 20 to 1 (reverse order)
    for (size_t i = 20; i > 0; i--)
    {
        cout << i << " ";
    }
    cout << endl << endl;


    // 7) list all numbers from 1 to 20, except 11
    for (size_t i = 0; i <= 20; i++)
    {
        if (i != 11) {
            cout << i << " ";
        }
    }
    cout << endl << endl;

    // 8) list all numbers from 1 to 20, except 11 and 12
    for (size_t i = 0; i <= 20; i++)
    {
        if (i != 11 || i!= 12) {
            cout << i << " ";
        }
    }
    cout << endl << endl;

}
