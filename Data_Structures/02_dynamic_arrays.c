#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *lista = NULL;
    int *cursor;
    int tamanho_da_lista = 10;

    lista = (int *) malloc(sizeof(int) * tamanho_da_lista);
    cursor = lista;

    for(int i=0; i<tamanho_da_lista;i++)
    {
        *cursor = i * 2;
        cursor++;
    }

    printfAccess the array elements using a cursor poiunter variable");
    cursor = lista;
    for(int i=0; i<tamanho_da_lista;i++)
    {
        printf("%d: %d\n", i, *cursor);
        cursor++;
    }


    printf("Accessing the array elements using square brackets:");
    cursor = lista;
    for(int i=0; i<tamanho_da_lista;i++)
    {
        printf("%d: %d\n", i, cursor[i]);
    }

}
