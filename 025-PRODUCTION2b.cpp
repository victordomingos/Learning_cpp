/* Produção 2 - parte II
   2019-05-02 Victor Domingos

   2. Ler nome, idade e valor a pagar. 
      - Se for menor de idade, a taxa de desconto é de 10%. 
      - Se for reformado (acima de 65 anos), o desconto é 
        de 20%. 
      - De 18 a 65, não tem desconto. 
 
      Exemplo: 
 
      ? Ana 
      ? 17 
      ? 100 
      ➔ Olá Ana, tens a pagar 90. 
*/

#include <iostream>

using namespace std;

int main()
{
    string nome;
    float idade;
    float valor, desconto, valor_final;

    // Ler dados
    cout << "\nNome? ";         cin >> nome;
    cout << "Idade? ";          cin >> idade;
    cout << "Valor a pagar? ";  cin >> valor;

    if (idade < 0)
    {
        cout << "\nEste programa ainda nao esta' preparado para oferecer descontos a viajantes no tempo.\n\n";
        return 1;
    }
    else if (idade < 18)    //Se for menor de idade, a taxa de desconto é de 10 % .
        desconto = 0.10;
    else if (idade > 65)    //Se for reformado(acima de 65 anos), o desconto é de 20 %.
        desconto = 0.20;
    else                    //De 18 a 65, não tem desconto.
        desconto = 0;

    valor_final = valor * (1 - desconto);
    cout << "\n-> Ola' Ana, tens a pagar " << valor_final << "." << endl;
    return 0;
}
