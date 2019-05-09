/* Produção 2 - parte III
   2019-05-02 Victor Domingos

   Ler 5 números para um array. 
   Calcular a média dos números positivos. 
*/

#include <iostream>

using namespace std;

int main()
{
    float nums[5] = { 0 };
    float positives_sum = 0;
    float positives_count = 0;
    float positives_mean = 0;

 
    // Ler 5 números para um array.
    cout << "\nPor favor, introduza 5 numeros (pressione ENTER depois de escrever cada um deles):";
    cout << "\n? ";     cin >> nums[0];
    cout << "? ";     cin >> nums[1];
    cout << "? ";     cin >> nums[2];
    cout << "? ";     cin >> nums[3];
    cout << "? ";     cin >> nums[4];

    // Calcular a média dos números positivos.
    for (int i = 0; i < 5; i++)
    {
        if (nums[i] >= 0)
        {
            positives_sum += nums[i];
            positives_count++;
        }
    }

    positives_mean = positives_sum / positives_count;

    cout << "\nIntroduziu " << positives_count << " numeros positivos, e a media destes e' " << positives_mean << ".";
    cout << endl << endl;
}
