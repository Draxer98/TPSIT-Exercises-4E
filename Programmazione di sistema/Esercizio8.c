/*Utilizzando le chiamate di sistema si scriva un programma concorrente che possa
essere invocato nel seguente modo:
./esame risultati.txt

dove risultati.txt è un nome assoluto di file.

Il processo P0 deve generare 2 processi figli: P1 e P2.
P1 deve interagire con l'utente, richiedendo delle stringhe (ogni stringa di lunghezza
massima pari a 50 caratteri) che provvede ad inviare a P2 utilizzando una pipe.
Il processo P1 continua a ricevere stringhe fin quando non riceve la stringa
"esci".
Il processo P2 legge le stringhe dalla pipe e le scrive in
ordine alfabetico nel file risultati.txt


Osservazione:
il comando sort, che risiede in /usr/bin/sort, è un filtro che può leggere
in input un flusso di dati e stamparlo quindi a video oppure in qualsiasi
altro file descriptor purchè opportunamente redirezionato.

esempio di utilizzo:

$ ./esame risultati.txt
Inserisci una stringa:
paolo
Inserisci una stringa:
luca
Inserisci una stringa:
anna
Inserisci una stringa:
tommaso
Inserisci una stringa:
alberto
Inserisci una stringa:
esci
Esecuzione terminata, esco.

$ cat risultati.txt
alberto
anna
luca
paolo
tommaso

osservazione:
ad ogni iterazione è opportuno aggiungere il carattere newline al termine
della stringa, in modo che nel file vengano scritte le stringhe una per riga
come nell'esempio. strcat(stringa, "\n");

nota operativa:
si presti attenzione a non dimenticare processi zombie quando il padre termina
l'esecuzione.*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Errore nell'inserimento");
        exit(1);
    }
    int pid, p1p2[2];
    char stringa[50];

    pipe(p1p2);

    pid = fork();

    if (pid == 0)
    {
        close(p1p2[0]);

        while (1)
        {
            printf("Inserisci parola: ");
            scanf("%s", stringa);

            if (strcmp(stringa, "esci") == 0)
            {
                close(p1p2[1]);
                exit(1);
            }
            else
            {
                strcat(stringa, "\n");
                write(p1p2[1], stringa, strlen(stringa));
            }
        }
    }

    pid = fork();

    if (pid == 0)
    {
        close(p1p2[1]);
        close(0);
        dup(p1p2[0]);
        close(p1p2[0]);

        execl("/usr/bin/sort", "sort", NULL);
        return -1;
    }
    close(p1p2[0]);
    close(p1p2[1]);

    wait(&pid);
    wait(&pid);

    return 0;
}