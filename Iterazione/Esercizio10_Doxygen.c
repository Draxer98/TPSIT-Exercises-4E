#include <stdio.h>

/**
 * @brief Calcola la somma dei numeri interi da 1 a n.
 *
 * Questo programma chiede all'utente di inserire un numero positivo,
 * quindi calcola la somma di tutti i numeri interi da 1 fino a quel numero.
 * 
 * @param argc Numero di argomenti della riga di comando.
 * @param argv Array di argomenti della riga di comando.
 * @return Restituisce 0 se il programma termina correttamente.
 */
int main(int argc, char *argv[])
{
    int n, i, somma;

    // Richiesta di un numero positivo all'utente
    do
    {
        printf("Inserisci un numero positivo: \n");
        scanf("%d", &n);
    } while (n < 0); // Continua a richiedere finché n non è positivo

    somma = 0;
    i = n;

    // Calcolo della somma dei numeri da n a 1
    do
    {
        somma = somma + i; // Aggiunge i alla somma
        i = i - 1;         // Decrementa i
    } while (i > 0); // Continua finché i è maggiore di 0

    // Stampa del risultato
    printf("La somma vale: %d\n\n", somma);

    return 0; // Fine del programma
}