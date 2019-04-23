// pythagoras - Calculate a right triangle's hypothenuse length given the length of the other two sides.
// 2019-04-23
// Victor Domingos

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
	float h, a, b;

	cout << "\nPythagorean Theorem - calculate a triangle's hypothenuse" << endl;
	cout << "--------------------------------------------------------" << endl << endl;
	cout << "Length of side A? ";	cin >> a;
	cout << "Length of side B? ";	cin >> b;

	h = sqrt(pow(a, 2) + pow(b, 2));

	cout << "\nLength of hypothenuse: ";
	cout << setprecision(3) << h << endl;
}
