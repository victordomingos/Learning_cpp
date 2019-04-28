// Some basic exercises on arrays
// 2019-04-27
// Victor Domintos

#include <iostream>

using namespace std;

int main() {
    int arr[10];
    
    cout << "Please enter a few integer numbers (press ENTER for each one):" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "? ";
        cin >> arr[i];
    }
    
    cout << "Thank you very much. These are the numbers you entered:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    
    cout << endl;
}