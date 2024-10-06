/*Dato un numero intero positivo N verificare se N è un numero primo.*/

#include <stdio.h>

int main(int argc, char *argv[])
{

    int a, i, resto = 0;

    do
    {
        printf("Inserisci un numero: ");
        scanf("%d", &a);
    } while (a < 1);

    i = a - 1;

    do
    {
        resto = a % i;
        if (resto == 0 && a != 2)
        {
            printf("Il numero non è primo\n");
            return 0;
        }
        i = i - 1;
    } while (i > 1);

    printf("Numero Primo\n");

    return 0;
}

