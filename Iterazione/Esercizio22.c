/*Dato un numero N calcolare e visualizzare tutte le coppie di numeri minori di N che
danno per somma il numero stesso. Non considerare la proprietà commutativa. */

#include <stdio.h>

int main(int argc, char *argv[])
{

    int n;
    int somma = 0;

    do
    {
        printf("Inserisci un numero: ");
        scanf("%d", &n);
    } while (n < 2);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + j == n && j >= i)
            {
                somma = i + j;
                printf("%d + %d = %d\n", i, j, n);
            }
        }
    }

    return 0;
}