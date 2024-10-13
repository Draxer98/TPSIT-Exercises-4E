/*Si crei un programma che nel momento dell'esecuzione popoli l'array
argv[] con una serie di numeri. Esempio: $ ./a.out 1 5 9 6
Il programma deve calcolare la media dei numeri inseriti da riga di
comando.
Suggerimento: si usi una funzione per calcolare la somma dei numeri.*/

#include <stdio.h>
#include <stdlib.h>

int sommaMedia(int argc, char *argv[], int *contatore)
{
    int somma = 0;
    for (int i = 1; i < argc; i++)
    {
        somma = somma + atoi(argv[i]);
        (*contatore)++;
    }

    return somma;
}

int main(int argc, char *argv[])
{
    int somma = 0;
    int contatore = 0;
    double media = 0;

    if (argc < 2)
    {
        printf("Errore nell'inserimento");
        exit(0);
    }

    somma = sommaMedia(argc, argv, &contatore);

    media = (double)somma / contatore;

    printf("La media è: %f", media);

    return 0;
}