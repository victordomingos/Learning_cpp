// Some basic exercises on arrays
// 2019-04-27
// Victor Domintos

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    long double arr[5];
    long double sum = 0;
    
    cout << "Please enter 5 numbers (press ENTER for each one):" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "? "; cin >> arr[i];
        sum += arr[i];
    }
    
    cout << "\nThank you very much. These are the numbers you entered:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    
    cout << "\n\n The sum of these is: " << setprecision(16) << sum << endl;
}