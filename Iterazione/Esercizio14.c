/*Dati due numeri interi positivi N1 ed N2 calcolare, mediante la somma
ripetuta, il prodotto dei due numeri e visualizzarli.*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int a, b;
    int somma = 0;

    do
    {
        printf("Inserisci A: ");
        scanf("%d", &a);

        printf("Inserisci B: ");
        scanf("%d", &b);

        somma = somma + a + b;

        printf("La somma totale dei numeri inseriti: %d\n", somma);

    } while (a >= 0 && b >= 0);

    return 0;
}