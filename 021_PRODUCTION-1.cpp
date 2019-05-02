/* Produção 1 (C++) - Nomes, idades e maioridade

   Pede ao utilizador que introduza sequencialmente 3 nomes de pessoas e as
   respetivas idades. De seguida o programa indica quem é o mais velho e
   quantas dessas pessoas são maiores de idade.
   
   Ex. (apenas resultado final):
        Mais velho: Abel
        Maioridade: 2

   2019-04-18
   Victor Domingos
*/

#include <iostream>
using namespace std;

int main()
{
    string nome1, nome2, nome3;
    int idade1, idade2, idade3;
    string mais_velho;
    int id_mais_velho = 0;
    int n_maiores = 0;
    string msg_idade_neg = "\nO valor referente 'a idade nao pode ser inferior a 0.\n";

    // Ler nomes e idades de 3 pessoas
    // Verificar se nenhuma das idades é um valor negativo.

    cout << "\nNome 1? ";     cin >> nome1;
    
    // TODO: Substituir isto por um while.
    for (int i = -1 ; i < 0; )
    {
        cout << "Idade? ";
        cin >> i;

        if (i < 0)
        {
            cout << msg_idade_neg;
        }
        else
        {
            idade1 = i;
        }
    }


    cout << "\nNome 2? ";     cin >> nome2;

    // TODO: Substituir ciclos 'for' por 'while'.
    for (int i = -1; i < 0; )
    {
        cout << "Idade? ";
        cin >> i;

        if (i < 0)
        {
            cout << msg_idade_neg;
        }
        else
        {
            idade2 = i;
        }
    }
    
    cout << "\nNome 3? ";     cin >> nome3;

    // TODO: Substituir isto por um while.
    for (int i = -1; i < 0; )
    {
        cout << "Idade? ";
        cin >> i;

        if (i < 0)
        {
            cout << msg_idade_neg;
        }
        else
        {
            idade3 = i;
        }
    }

   
    // Verificar primeiro se todas as idades são iguais
    if (idade1 == idade2 && idade2 == idade3)
    {
        mais_velho = "sao todos da mesma idade";
    }
    else 
    {
        // Comparar idades para determinar qual é o mais velho
        if (idade1 >= idade2  &&  idade1 > idade3)
        {
            id_mais_velho = idade1;
            if (idade1 == idade2)
            {
                mais_velho = nome1 + " e " + nome2;
            }
            else
            {
                mais_velho = nome1;
            }

        }
        if (idade2 >= idade3  &&  idade2 > idade1)
        {
            id_mais_velho = idade2;
            if (idade2 == idade3)
            {
                mais_velho = nome2 + " e " + nome3;
            }
            else
            {
                mais_velho = nome2;
            }
        }
        if (idade3 >= idade1  &&  idade3 > idade2)
        {
            id_mais_velho = idade3;
            if (idade3 == idade1)
            {
                mais_velho = nome1 + " e " + nome3;
            }
            else
            {
                mais_velho = nome3;
            }
        }

    }
      

    // Contar quantas pessoas têm idade > 18 anos
    if (idade1 >= 18)  n_maiores++;
    if (idade2 >= 18)  n_maiores++;
    if (idade3 >= 18)  n_maiores++;

    // Escrever nome do mais velho.
    // Escrever nº de pessoas maiores de 18 anos:. Ex.:
    //    Mais velho: NOME
    //    Maioridade: [nº de pessoas maiores de 18 anos]
    cout << "\nMais velho: " << mais_velho;
    cout << "\nMaioridade: " << n_maiores << endl;
}
