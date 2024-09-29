/*Dato N un numero intero positivo, generare e visualizzare in ordine
crescente i numeri compresi maggiori uguali di -N e minori uguali di N.*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int n, negativo = 0;
    int i = 0;

    do
    {
        printf("Inserisci un numero positivo: ");
        scanf("%d", &n);
    } while (n < 0);

    negativo = n * (-1);
    i = negativo;

    while (i <= n)
    {
        printf("%d ", i);
        i++;
    }
    return 0;
}