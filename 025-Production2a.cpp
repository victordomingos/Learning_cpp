/* Produção 2 - parte I
   2019-05-02 Victor Domingos
  
   1. Ler nome(string) e ano de nascimento(int); escreve a idade.

       Exemplo:

       ? Ana 
       ? 2000 
       ➔ Olá Ana, tens 19 anos.
*/

#include <iostream>

using namespace std;

int main()
{
    string nome;
    int ano, idade;

    // Ler nome(string) 
    cout << "\n? ";     cin >> nome;

    // Ler ano de nascimento(int)
    cout << "? ";       cin >> ano;

    // escrever a idade.
    idade = 2019 - ano;

    if (ano <= 2019)
    {
        cout << "-> Ola' " << nome << ", tens " << idade << " anos.\n\n";
        return 0;
    }
    else
    {
        cout << "Ola' " << nome << ". Parece que temos aqui alguem que viaja no tempo e veio do futuro...\n\n";
        return 1;
    }
}
