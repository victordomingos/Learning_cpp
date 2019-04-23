// bmi - calculate the Body Mass Index (BMI) for an adult
// 2019-04-23
// Victor Domingos

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	float weight, height, bmi;
	
	cout << "BMI Calculator" << endl;
	cout << "--------------" << endl << endl;
	cout << "Weight (kg)? ";	cin >> weight;
	cout << "Height (m)? ";		cin >> height;
	
	bmi = weight / (height * height);
	cout << "BMI: " << fixed << setprecision(1) << bmi << endl;
}
