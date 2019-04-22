/* toy_exercise1.cpp: print a text-mode graph of a given temperature

   Ask the user for an integer number and then display an indicator
   like the one below (# means 2 degrees; + means 1 degree):

	 How many degrees (enter an integer number)?
	 |### ### ### ##+

   2019-04-16
   Victor Domingos
 */
#include <iostream>
using namespace std;

int main()
{
	signed int temp;
	string suffix, prefix;
	string result = "";

	cout << "\"GRAPHICAL REPRESENTATION OF A CITY'S TEMPERATURE\"" << endl;
	cout << "(# means 2 degrees; + means 1 degree)" << endl << endl;

	cout << "Please enter the temperature in degrees (an integer number): ";
	cin >> temp;

	if (temp > 0)
	{
		prefix = " |";
		suffix = (temp % 2 != 0) ? "+" : "";

		for (int i = 2; i <= temp; i += 2)
		{
			if (i % 2 == 0)    result += "#";
			if (i % 6 == 0)    result += " ";
		}
	}
	else if (temp < 0) {
		prefix = (temp % 2 != 0) ? " +" : " ";
		suffix = "|";

		for (signed int i = -2; i >= temp; i = i - 2)
		{
			if (abs(i) % 2 == 0)	result = "#" + result;
			if (abs(i) % 6 == 0)	result = " " + result;
		}
	}
	else {
		prefix = " |";
		suffix = "";
	}

	cout << endl << prefix << result << suffix << endl;
}
