// age_status - determine if a person is considered adult (>18 years old)
// 2019-04-10
// Victor Domingos

#include <iostream>
using namespace std;

int main()
{
    int age;
    
    cout << endl << "What is your age? "; 
    cin >> age;

    if (age < 18)
    {
        cout << "Legally you are not an adult yet. Please be patient." << endl;
    }
    else
    {
        cout << "You are legally considered an adult citizen.\nGreat. Now, please be responsible.\n\n";
    }
}
