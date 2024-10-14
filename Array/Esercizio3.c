/*Chiedere in input 10 interi e inserirli in un array.
Stampare a video prima tutti i numeri pari e
in seguito tutti i numeri dispari

Esempio:
input 5 6 9 11 12 13 14 10 8 21
output
6 12 14 10 8
5 9 11 13 21*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int array[10];
    int n = sizeof(array) / sizeof(array[0]);

    for (int i = 0; i < n; i++)
    {
        printf("Inserisci numero: ");
        scanf("%d", &array[i]);
    }

    printf("NUMERI PARI\n");
    for (int i = 0; i < n; i++)
    {
        if (array[i] % 2 == 0)
        {
            printf("%d ", array[i]);
        }
    }

    printf("\nNUMERI DISPARI\n");
    for (int i = 0; i < n; i++)
    {
        if (array[i] % 2 != 0)
        {
            printf("%d ", array[i]);
        }
    }

    return 0;
}