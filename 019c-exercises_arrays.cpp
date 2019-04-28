// Some basic exercises on arrays
// 2019-04-27
// Victor Domintos

#include <iostream>

using namespace std;

int main() {
    int arr[10] = {1, 13, 22, 98, 44, 99, 19, 87, 71, 39};
    int total = 0, even = 0, odd = 0;
    int greater_than_50 = 0;
    int total_even = 0, total_odd = 0;
    string even_numbers = "", odd_numbers = "";
    float mean_arr = 0, mean_even = 0, mean_odd = 0;
    int new_number = 0, n = 0;
    
    
    // Sum all numbers and count those greater than 50
    for (int i = 0; i < 10; i++)
    {
        total += arr[i];
        if (arr[i] > 50)
            greater_than_50++;
    }
    cout << "The sum of all numbers is " << total << ".";
    cout << "\n\nThere are " << greater_than_50 << " numbers greater than 50.";
    
    
    // List all numbers
    cout << "\n\nThese are all the numbers being considered:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " / ";
    }
    cout << "\b\b";  // Just removing the last slash character ;-P
    
    
    // Count and list only even numbers
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] % 2 == 0)
        {
            even_numbers = even_numbers + to_string(arr[i]) + " ";
            even++;
        }
    }
    cout << "\n\nThese " << even << " numbers are even:\n";
    cout << even_numbers;


    // Count and list only odd numbers
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] % 2 != 0)
        {
            odd_numbers = odd_numbers + to_string(arr[i]) + " ";
            odd++;
        }
    }
    cout << "\n\nThese " << odd << " numbers are odd:\n";
    cout << odd_numbers;


    // Calculate mean of all values in the array
    total = 0;
    for (int i = 0; i < 10; i++)
        total += arr[i];

    mean_arr = (float)total / 10.0;
    cout << "\n\nThe mean for this data set is " << mean_arr;


    // Calculate mean of even values in the array
    total_even = 0;
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] % 2 == 0)
            total_even += arr[i];
    }
    mean_even = (float)total_even / 10.0;
    cout << "\nThe mean of all even values is " << mean_even;


    // Calculate mean of odd values in the array
    total_odd = 0;
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] % 2 != 0)
            total_odd += arr[i];
    }
    mean_odd = (float)total_odd / 10.0;
    cout << "\nThe mean of all odd values is " << mean_odd;


    // Calculate the same 3 means, but all in a single loop
    total = total_even = total_odd = 0;
    mean_arr = mean_even = mean_odd = 0;
    even = odd = 0;
    
    for (int i = 0; i < 10; i++)
    {
        total += arr[i];
        if (arr[i] % 2 == 0)
        {
            even++;
            total_even += arr[i];
        }
        else
        {
            odd++;
            total_odd += arr[i];
        }
    }
    mean_arr = (float)total / 10.0;
    mean_even = (float)total_even / 10.0;
    mean_odd = (float)total_odd / 10.0;
    cout << "\n\nThe mean of all values is " << mean_arr;    
    cout << "\nThe mean of all " << even << " even values is " << mean_even;
    cout << "\nThe mean of all " << odd << " odd values is " << mean_odd;
    
    
    // Start by listing the array. Ask the user for a position of the array and
    // a new number, then replace the old number at that position with the new 
    // one. List the array again.
    cout << "\n\n\nThis is the current list: ";
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << ", ";
    }
    
    cout << "\b\b\nPlease choose a position to replace (0-9): ";
    cin >> n;
    cout << "\b\b\nPlease enter a new integer number for that position: ";
    cin >> new_number;
    arr[n] = new_number;
    
    cout << "Done! This is the current list: ";
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << "\b\b\n\n";
}