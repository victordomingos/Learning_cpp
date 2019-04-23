// secs2hms - convert a given number of seconds into hours, minutes and seconds.
// 2019-04-23
// Victor Domingos

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int h, m, s;

	cout << "\nConvert seconds to hours, minutes and seconds" << endl;
	cout << "---------------------------------------------" << endl << endl;
	cout << "How many seconds? ";	cin >> s;

	h = s / 3600;	 // integer division
	s = s % 3600;	 // extract just the remainder (== minutes+seconds)
	m = s / 60;	 // again, integer division
	s = s % 60;	 // again, extract just the remaining seconds

	cout << "Time: ";

	// setfill() sets the character used for padding
	// setw() sets the width of the output field
	cout << setfill('0') << setw(2) << h << "h ";
	cout << setfill('0') << setw(2) << m << "m ";
	cout << setfill('0') << setw(2) << s << "s" << endl;
}
