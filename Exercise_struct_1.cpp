// Exercise_struct_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct carType
{
    int year=0;
    string brand;
    char category;
};

int main()
{
    carType c;
    
    cout << "\nPlease enter the details of the car:\n";
    cout << "Year? ";        cin >> c.year;
    cout << "Brand? ";       cin >> c.brand;
    cout << "Category? ";    cin >> c.category;

    cout << "\nThis is the info you provided:";
    cout << "\nYear: " << c.year;
    cout << "\nBrand: " << c.brand;
    cout << "\nCategory: " << c.category << endl;


    // Now into an array:
    carType cars[10];
    char op = 'Y';

    for (size_t i = 0; i < 10 && toupper(op) == 'Y'; i++)
    {
        cout << "\nPlease enter the details of the car:\n";
        cout << "Year? ";        cin >> cars.year;
        cout << "Brand? ";       cin >> cars.brand;
        cout << "Category? ";    cin >> cars.category;

        cout << "\nDo you want to enter another car (Y/n)? ";
        cin >> op;

        cout << "Car #\t Year: \tBrand: \nCategory: " << endl;
        for (size_t i = 0; i < 10 && cars[i].year == 0; i++)
        {
            cout << i << "\t " << c[i].year << "\t" << c[i].brand << "\t" << c[i].category << endl;
        }
    }
}
