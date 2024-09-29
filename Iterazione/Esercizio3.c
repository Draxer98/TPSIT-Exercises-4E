/*Dato N un numero intero positivo, generare e visualizzare in ordine crescente i numeri dispari
minori o uguali a N.*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int n, i = 0;

    do
    {
        printf("Inserisci un numero positivo: ");
        scanf("%d", &n);
    } while (n < 0);

    while (i <= n)
    {
        if (i % 2 != 0)
        {
            printf("%d ", i);
        }

        i++;
    }
    return 0;
}