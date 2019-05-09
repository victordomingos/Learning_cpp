/* Produ��o 2 - parte IV
   2019-05-02 Victor Domingos

   Ler 5 n�meros para um array.
   Escrever numa s� linha : 
   
   �H� x pares, y �mpares, z maiores que o primeiro, w abaixo da m�dia.�
*/

#include <iostream>

using namespace std;

int main()
{
    int nums[5] = { 0.0 };
    int nums_sum = 0;
    int nums_mean = 0.0;
    int even_count = 0;
    int odd_count = 0;
    int greater_than_first_count = 0;
    int below_mean_count = 0;

    // Ler 5 n�meros para um array.
    cout << "\nPor favor, introduza 5 numeros (pressione ENTER depois de escrever cada um deles):";
    cout << "\n? ";   cin >> nums[0];
    cout << "? ";     cin >> nums[1];
    cout << "? ";     cin >> nums[2];
    cout << "? ";     cin >> nums[3];
    cout << "? ";     cin >> nums[4];

    // Calcular a soma de todos os n�meros.
    // Contar pares.
    // Contar �mpares.
    // Contar maiores que o primeiro.
    for (int i = 0; i < 5; i++)
    {
        nums_sum += nums[i];

        if (nums[i] > nums[0])
            greater_than_first_count++;

        if (nums[i] % 2 == 0)
            even_count++;
        else
            odd_count++;
    }

    // Calcular a m�dia
    nums_mean = nums_sum / 5;

    // Contar n�meros abaixo da m�dia

    for (int i = 0; i < 5; i++)
    {
        if (nums[i] < nums_mean)
            below_mean_count++;
    }

    // Escrever resultado
    cout << "\nHa' " << even_count << " pares, ";
    cout << odd_count << " impares, ";
    cout << greater_than_first_count << " maiores que o primeiro, ";
    cout << below_mean_count << " abaixo da media.";
    cout << endl << endl;
}