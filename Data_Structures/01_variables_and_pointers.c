#include <stdio.h>

int main ()
{
    int x = 20;
    int *p = NULL;

    p = &x;

    printf("\nValor de X: \t\t\t\t%d", x);
    printf("\nEndereço de mem. da var. X: \t\t%p", p);
    
    printf("\nEndereço de mem. da variável apontada:\t%d", *p);
    printf("\nEndereço de mem. guardado no p:\t\t%p", p);
    
    printf("\nEndereço de mem. da variável p:\t\t%p", &p);

    printf("\nPergunta: que valor é este? :\t\t%p", &*p);
    
    printf("\n\n\n");
    return 0;
}
