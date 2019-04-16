// Producao_0.cpp :.
//

#include <iostream>
using namespace std;

int main()
{
    string nome1, nome2;
    int idade1, idade2;
    string maioridade = "\nMaioridade: ";

    // Ler nomes e respetivas idades
    cout << "\nNome da 1a. pessoa?  ";      cin >> nome1;
    cout << "Idade da 1a. pessoa? ";        cin >> idade1;

    cout << "\nNome da 2a. pessoa?  ";      cin >> nome2;
    cout << "Idade da 2a. pessoa? ";        cin >> idade2;


    // Escrever o nome do mais velho (Mais velho: NOME)
    if (idade1 > idade2)        cout << "\nMais velho: " << nome1;
    else if (idade1 < idade2)   cout << "\nMais velho: " << nome2;
    else                        cout << "\nMais velho: sao da mesma idade.";
  

    // Se forem maiores de idade, escrever os respetivos nomes 
    // (ou "nenhum", se nenhum for maior)
    if (idade1 >= 18)                   maioridade += nome1;
    if (idade1 >= 18 && idade2 >= 18)   maioridade += ", ";
    if (idade2 >= 18)                   maioridade += nome2;
    if (idade1 < 18 && idade2 < 18)     maioridade += "nenhum.";

    cout << maioridade << endl;
}
