/* fahren2celsius: Convert a temperature value from Fahrenheit to Celsius degrees
   
        tempF = 32 + (9 ∗ tempC / 5)

   2019-05-02
   Victor Domingos
*/

#include <iostream>

using namespace std;

int main()
{
    float temp_fahr, temp_c;

    cout << "Temperature (Fahrenheit)? ";     cin >> temp_fahr;

    temp_c = (temp_fahr - 32) / 1.8;

    cout << "\nConverted to Celsius degrees: " << temp_c;
}
