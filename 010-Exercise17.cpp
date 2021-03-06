/* Exercise17: 3 Cities and their temperatures

   Ask the user for 3 city names and their respective temperatures (integer
   numbers).

   - What is the highest temperature?
   - What is the hottest city?
   - What is the lowest temperature?
   - What is the coldest city?

   2019-04-19
   Victor Domingos
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string city1, city2, city3;
	string hottest_city = "";
	string coldest_city = "";
	int temp1, temp2, temp3;
	int highest_temp;
	int lowest_temp;

	cout << "\nName of 1st city: ";		cin >> city1;
	cout << "Temperature: ";			cin >> temp1;

	cout << "\nName of 2nd city: ";		cin >> city2;
	cout << "Temperature: ";			cin >> temp2;

	cout << "\nName of 3rd city: ";		cin >> city3;
	cout << "Temperature: ";			cin >> temp3;

	if ((temp1 == temp2) && (temp2 == temp3))
	{
		cout << "\nAll cities had the same temperature!\n";
		cout << "Highest temperature: " << temp1 << endl;
	}
	else
	{
		// Get highest temperature(s)
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


		//Get lowest temperature(s)
		lowest_temp = temp1;
		coldest_city = city1;
		if (lowest_temp > temp2)
		{
			lowest_temp = temp2;
			coldest_city = city2;
		}
		else if (lowest_temp == temp2)
		{
			coldest_city = "both " + city1 + " and " + city2;
		}

		if (lowest_temp > temp3)
		{
			lowest_temp = temp3;
			coldest_city = city3;
		}
		else if (lowest_temp == temp3)
		{
			coldest_city = "both " + coldest_city + " and " + city3;
		}


		cout << "\nHottest city: " << hottest_city << endl;
		cout << "Highest temperature: " << highest_temp << endl;

		cout << "\nColdest city: " << coldest_city << endl;
		cout << "Lowest temperature: " << lowest_temp << endl;
	}
}
