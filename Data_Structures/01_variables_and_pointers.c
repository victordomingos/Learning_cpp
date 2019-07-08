#include <stdio.h>

int main ()
{
    int x = 20;
    int *p = NULL;

    p = &x;

    printf("\nValor de X: \t\t\t\t%d", x);
    printf("\nEndereço de mem. da var. X: \t\t%p", (void *)p);
    
    printf("\nEndereço de mem. da variável apontada:\t%d", *p);
    printf("\nEndereço de mem. guardado no p:\t\t%p", (void *)p);
    
    printf("\nEndereço de mem. da variável p:\t\t%d", (unsigned int)&p);

    printf("\nPergunta: que valor é este? :\t\t%p", (void *)&*p);
    
    printf("\n\n\n");
    return 0;
}
