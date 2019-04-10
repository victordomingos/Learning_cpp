// circle_area.cpp - Calculate the area of a circle from a radius length entered by the user.
// 2019-04-10
// Victor Domingos

#include <iostream>
using namespace std;

int main()
{
	float radius, area;
	float pi = 3.141592653589793;

	cout << "Please enter the radius length: ";
	cin >> radius;
	
	area = pi * radius * radius;
	cout << "The area of that circle is " << area;
}
