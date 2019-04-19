/* Exercise16: 3 Cities and their temperatures

   Ask the user for 3 city names and their respective temperatures (integer
   numbers). What is the highest temperature? What is the hottest city?

   2019-04-19
   Victor Domingos
*/

#include <iostream>

using namespace std;

int main()
{
	string city1, city2, city3;
	string hottest_city = "";

	int temp1, temp2, temp3;
	int highest_temp;

	cout << "\nName of 1st city: ";		cin >> city1;
	cout << "Temperature: ";			cin >> temp1;

	cout << "\nName of 2nd city: ";		cin >> city2;
	cout << "Temperature: ";			cin >> temp2;

	cout << "\nName of 3rd city: ";		cin >> city3;
	cout << "Temperature: ";			cin >> temp3;

	if ((temp1 == temp2)  && (temp2 == temp3))
	{
		cout << "\nAll cities had the same temperature!\n";
		cout << "Highest temperature: " << temp1;
	}
	else
	{
		highest_temp = temp1;
		hottest_city = city1;
		if (highest_temp < temp2)
		{
			highest_temp = temp2;
			hottest_city = city2;
		}
		else if (highest_temp == temp2)
		{
			hottest_city = "both" + city1 + " and " + city2;
		}


		if (highest_temp < temp3)
		{
			highest_temp = temp3;
			hottest_city = city3;
		}
		else if (highest_temp == temp3)
		{
			hottest_city = "both " + hottest_city + " and " + city3;
		}

		cout << "\nHottest city: " << hottest_city << endl;
		cout << "Highest temperature: " << highest_temp << endl;
	}
}
