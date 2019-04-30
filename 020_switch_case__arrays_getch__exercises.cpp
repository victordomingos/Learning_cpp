#include <iostream>
#include <conio.h>
#include <time.h>

using namespace std;

#define MAX_ELEMENTS 10

void display_menu()
{
    cout << "\nPROGRAMA MANIPULA ARRAY\n";
    cout << "\n";
    cout << "i - initialize array" << endl;
    cout << "l - list array elements" << endl;
    cout << "ESC - quit this application" << endl;
    cout << "-------------------------" << endl;
    cout << "a - " << endl;
    cout << "b - " << endl;
    cout << "c - " << endl;
    cout << "d - " << endl;
    cout << "e - " << endl;
    cout << "f - " << endl;
    cout << "g - " << endl;
    cout << "? - Display this menu" << endl;
}

int main()
{
    char op = '?';
    int dados[MAX_ELEMENTS] = { 1, 13, 22, 98, 44, 99, 19, 87, 71, 39 };
    float soma, n;
    float even_mean, odd_mean, even_sum, odd_sum, even_count, odd_count;
    int highest, lowest;

    int arr[MAX_ELEMENTS] = { 0 };

    display_menu();

    do
    {
        op = _getch();

        cout << endl;

        switch (op)
        {
            // sum all elements -----------------------------------------------------
        case 'a':
            soma = 0;
            for (int i = 0; i < MAX_ELEMENTS; i++)
                soma += arr[i];
            cout << "\nThe sum of all elements is " << soma << endl;
            break;
        // count all even values --------------------------------------------------
        case 'b':
            even_count = 0;
            for (int i = 0; i < MAX_ELEMENTS; i++)
            {
                if (arr[i] % 2 == 0)
                    even_count++;
            }
            cout << "\nThere are " << even_count << " even elements." << endl;
            break;
            // calculate mean of all elements ---------------------------------------
        case 'c':
            soma = 0;
            for (int i = 0; i < MAX_ELEMENTS; i++)
                soma += arr[i];
            cout << "\nThe mean of all elements is " << soma / MAX_ELEMENTS << endl;
            break;
            // sum all even values --------------------------------------------------
        case 'd':
            soma = 0;
            n = 0;
            for (int i = 0; i < MAX_ELEMENTS; i++)
            {
                if (arr[i] % 2 == 0)
                {
                    soma += arr[i];
                    n++;
                }
            }
            cout << "\nThe mean of all even elements is " << soma / n << endl;
            break;
        // Determine if the mean of even elements is greater than the mean of odd elements
        case 'e':
            even_mean = odd_mean = even_sum = odd_sum = even_count = odd_count = 0;

            for (int i = 0; i < MAX_ELEMENTS; i++)
                if (arr[i] % 2 == 0)
                {
                    even_sum += arr[i];
                    even_count++;
                }
                else
                {
                    odd_sum += arr[i];
                    odd_count++;
                }
            
            if (even_count == 0 or odd_count == 0)
            {
                cout << "\nThere are no even or no odd values, so we can't compare their mean values (division by zero).";
            }
            else
            {
                even_mean = even_sum / even_count;
                odd_mean = odd_sum / odd_count;
                if (even_mean > odd_mean)
                    cout << "The average of all even values is greater than the average of all odd values.";
                else
                    cout << "The average of all even values is lower than the average of all odd values.";
            }
            break;
        // Calculate the difference between the highest and the lowest value
        case 'f':
            highest = lowest = arr[0];
            for (int i = 0; i < MAX_ELEMENTS; i++)
            {
                if (highest < arr[i])
                    highest = arr[i];
                if (lowest > arr[i])
                    lowest = arr[i];
            }
            cout << "\n\nThe highest value is " << highest << endl;
            cout << "The lowest value is " << lowest << endl;
            cout << "The difference between them is " << highest - lowest << endl;
            break;
        // Generate random integers between 0 and 100 to fill the array
        case 'g':
            srand(time(NULL));

            for (int i = 0; i < MAX_ELEMENTS; i++)
                arr[i] = rand() % 101;
        
            break;
        // initialize array -----------------------------------------------------
        case 'i':
            for (int i = 0; i < MAX_ELEMENTS; i++)
                arr[i] = dados[i];
            break;
        // list all elements ----------------------------------------------------
        case 'l':
            for (int i = 0; i < MAX_ELEMENTS; i++)
                cout << arr[i] << " ";
            break;
        case '?':
            display_menu();
            break;
        // display a message and ask for correct input --------------------------
        default:
            if (op != 27)
                cout << "\nOpcao desconhecida!\n";
            break;
        }
    } while (op != 27);

    cout << endl;
}
