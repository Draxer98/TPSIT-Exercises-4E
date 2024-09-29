/*Dato N un numero intero positivo, generare e visualizzare in ordine crescente i primi N numeri
interi positivi.*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int n, i = 0;

    do
    {
        printf("inserisci un numero positivo: ");
        scanf("%d", &n);
    } while (n < 0);

    while (i < n)
    {
        printf("%d ", i);
        i++;
    }

    return 0;
}