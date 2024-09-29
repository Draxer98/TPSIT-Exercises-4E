/*Dati due numeri interi positivi N1 e N2 con N2>N1, generare e
visualizzare in ordine crescente i numeri interi compresi
nell'intervallo chiuso [N1,N2]. */

#include <stdio.h>

int main(int argc, char *argv[])
{
    int a, b;
    int i = 0;

    do
    {
        printf("Inserisci il primo numero: ");
        scanf("%d", &a);
        printf("Inserisci il secondo numero: ");
        scanf("%d", &b);
    } while (b < a && a < 0 && b < 0);

    i = a + 1;

    while (i < b)
    {
        printf("%d ", i);
        i++;
    }

    return 0;
}