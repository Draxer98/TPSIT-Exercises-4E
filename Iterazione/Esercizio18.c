/*Data una misura di tempo espressa in secondi S1, convertirla in ore H,
minuti M e secondi S.

Esempio: se il numero dei secondi è 1630, si dovrà ottenere, in uscita
dal programma, 0h 27m 10s.*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int numero, secondi;
    int minuti = 0;
    int ore = 0;

    do
    {
        printf("Inserisci dei secondi: ");
        scanf("%d", &numero);
    } while (numero < 1);

    secondi = numero % 60;
    minuti = numero / 60;
    minuti = minuti % 60;
    ore = minuti / 60;

    printf("%d : %d : %d \n", ore, minuti, secondi);

    return 0;
}