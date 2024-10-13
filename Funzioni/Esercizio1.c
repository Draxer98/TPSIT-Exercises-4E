/*Leggere in input da tastiera due numeri maggiori di 0 e farne la somma. */

#include <stdio.h>

int verifica(int a, int b)
{
    int positivo = 0;
    if (a < 1 || b < 1)
    {
        printf("Hai inserito un numero negativo\n\n");
        positivo = 1;
    }

    return positivo;
}
int main(int argc, char *argv[])
{
    int a, b;
    int positivo;
    int somma = 0;
    do
    {
        positivo = 0;
        printf("Inserisci primo numero: ");
        scanf("%d", &a);

        printf("Inserisci il secondo numero: ");
        scanf("%d", &b);

        positivo = verifica(a, b);
    } while (positivo == 1);

    somma = a + b;
    printf("La somma è: %d", somma);
}