// Some basic exercises on arrays
// 2019-04-27
// Victor Domintos

#include <iostream>
#include <time.h>

using namespace std;

// Generate 10 random numbers between 0 and 50, store them in an array,
// and finaly list the contents of the array to the screen.
int main() {
    int i;
    int arr[10];
    
    srand(time(NULL));
    for (i = 0; i < 10; i++)
        arr[i] = rand() % 51;  // include both 0 and 50
    
    cout << "\nThese are just a few random numbers:\n";
    for (i = 0; i < 10; i++)
        cout << arr[i] << " ";
}