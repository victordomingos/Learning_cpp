// A short exercise with a counter variable; using special characters on Windows console.
// 2019-04-17
// Victor Domingos

#include <iostream>
#include<windows.h> 

using namespace std;

int main()
{
    int counter = 0;
    int x, y, z;
    
    UINT oldconsole = GetConsoleCP();  // Save current console codepage (win)

    // Set Windows console to Latin1 codepage
    SetConsoleOutputCP(1252);
    SetConsoleCP(1252);


    cout << "Por favor, introduza 3 números (pressione ENTER em cada um):\n";
    cin >> x;
    cin >> y;
    cin >> z;

    if (x > 0)  counter++;
    if (y > 0)  counter++;
    if (z > 0)  counter++;

    cout << endl << counter << endl;

    // Undo codepage changes before the end of the program
    SetConsoleOutputCP(oldconsole);  

    return 0;
}
