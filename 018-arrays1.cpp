// Basic array operations
// 2019-04-24
// Victor Domingos

#include <iostream>

using namespace std;

int main()
{
    // ------------------------------------------------------ declaration
    int array[10];
    int soma, count, even;

    // --------------------------------------------------- initialization
    array[0] = 1;
    array[1] = 13;
    array[2] = 22;
    array[3] = 98;
    array[4] = 44;
    array[5] = 99;
    array[6] = 19;
    array[7] = 87;
    array[8] = 71;
    array[9] = 39;
    soma = 0;
    count = 0;
    even = 0;

    // ----------------------------------- calculate sum of all elements
    for (size_t i = 0; i < 10; i++)
    {
        soma += array[i];
    }

    cout << "SUM: " << soma << endl << endl;


    // ----------------------------------- count elements greater than 50
    for (size_t i = 0; i < 10; i++)
    {
        count += array[i] > 50 ? 1 : 0;
    }

    cout << count << " elements greater than 50." << endl;


    // ------------------------------------------------ count even values
    for (size_t i = 0; i < 10; i++)
    {
        if (array[i] % 2 == 0)
        {
            even++;
        }
    }

    cout << even << " even elements." << endl;

    // ------------------------------- output odd values in a single line
    cout << "These are the odd values: ";

    for (size_t i = 0; i < 10; i++)
    {
        if (array[i] % 2 != 0)
        {
            cout << array[i] << " ";
        }
    }
}
