/*Si scriva un’applicazione concorrente che presenti la seguente interfaccia:

cercaStringhe FileIn

dove FileIn è un nome assoluto di file.

L’applicazione deve contare il numero di volte in cui un insieme di stringhe
che l’utente inserisce da terminale (una alla volta) compaiono all’interno
del file passato come parametro in argv[1].
Se in una riga del file una parola compare più volte, al fine del conteggio,
considerare solamente la prima occorrenza.
L’applicazione termina quando l’utente inserisce la stringa “fine”.
L’applicazione deve visualizzare il numero di volte in cui ogni stringa
compare nel file*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Errore nell'inserimento");
        exit(0);
    }
    int p0p1[2], pid;
    char stringa[60];

    pipe(p0p1);

    if (argv[2] == "Fine" || argv[2] == "fine" || argv[2] == "FINE")
    {
        pid = fork();

        if (pid == 0)
        {
            p0p1[0];
            close(1);
            dup(p0p1[1]);
            close(p0p1[1]);

            execl("/usr/bin/grep", "grep", "-c", argv[2], argv[1], (char *)0);
            return -1;
        }

        close(p0p1[1]);
        read(p0p1[0], stringa, sizeof(stringa));
        printf("Il file ha %d %s", atoi(stringa), argv[2]);
    }

    return 0;
}