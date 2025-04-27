/*Il file.txt rappresenta le fatture dell’ultimo mese della ditta ProgrammatoriHero srl
e contiene 3 campi: codice, “pagato” o “insoluto”, l’importo

Si vuole realizzare un programma concorrente in linguaggio C che mostri a video l'importo totale delle
fatture emesse.

Si usi la seguente procedura:
Si generi un processo figlio P1 che legge il file e lo manda al processo P2 il quale
estrapola la terza colonna del file, e la manda al processo P0.
Il processo P0 riceve quindi tutti gli importi, ne calcola il totale e lo mostra a video.

Note operative
Il processo P1 usi il comando cat per mostrare il contenuto del file e inviarlo a P2
Il processo P2 usi il comando: awk '{print $3}' per estrapolare la terza colonna
Il processo P2 deve inviare al processo P0 la terza colonna
Il processo P0 deve leggere in input tutti i valori e per ogni lettura deve incrementare la variabile accumulatore “totale”

Osservazione:
strncat(strimporto, &buffer[0], sizeof(buffer[0]))
Aggiunge in coda alla stringa strimporto il carattere buffer[0] la cui dimensione è sizeof(buffer[0])

Osservazione:
char *ptr;
double x = strtod(strimporto, &ptr);
strtod converte la stringa strimporto in double.

Osservazione:
strimporto[0] = '\0';
Pone in posizione 0 di una stringa il carattere terminatore, in questo modo si resetta a livello logico una stringa
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Errore nell'inserimento");
        exit(0);
    }

    int pid, p1p2[2], p2p0[2], totale;
    char buffer[1], *ptr, strimporto[100];

    pipe(p1p2);

    pid = fork();

    if (pid == 0)
    {
        close(p1p2[0]);
        close(1);
        dup(p1p2[1]);
        close(p1p2[1]);

        execl("usr/bin/cat", "cat", argv[1], NULL);
        return -1;
    }

    pipe(p2p0);

    pid = fork();

    if (pid == 0)
    {
        close(p1p2[1]);
        close(0);
        dup(p1p2[0]);
        close(p1p2[0]);

        close(p2p0[0]);
        close(1);
        dup(p2p0[1]);
        close(p2p0[1]);

        execl("/usr/bin/awk", "awk", "{print $3}", NULL);
        return -1;
    }

    close(p1p2[0]);
    close(p1p2[1]);
    close(p2p0[1]);

    while (read(p2p0[0], &buffer, sizeof(buffer)) > 0)
    {
        strncat(strimporto, &buffer[0], sizeof(buffer[0]));
        if (buffer[0] == '\n')
        {
            totale = totale + strtod(strimporto, &ptr);
            strimporto[0] = '\0';
        }
    }

    close(p2p0[0]);
    
    return 0;
}