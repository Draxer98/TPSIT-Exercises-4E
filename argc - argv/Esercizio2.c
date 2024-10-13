/*Si scriva un programma che calcoli l’elevazione a potenza del valore intero
passato come primo argomento per il secondo argomento intero.

Esempio:

$./es 2 3
2 ^ 3 = 8*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    if (argc != 3)
    {
        printf("Errore: Inserire due argomenti.\n");
        exit(0);
    }

    int base = atoi(argv[1]);
    int esponente = atoi(argv[2]);
    int risultato = 1;

    for (int i = 0; i < esponente; i++)
    {
        risultato *= base;
    }

    printf("%d ^ %d = %d\n", base, esponente, risultato);

    return 0;
}