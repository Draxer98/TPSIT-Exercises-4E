#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Errore nell'inserimento");
        exit(1); // Ho cambiato il codice di uscita per coerenza
    }

    int pid;
    int p0p1[2], p2p0[2];
    int contatoreVocali = 0;

    pipe(p0p1);

    pid = fork();

    if (pid < 0)
    {
        printf("Errore di creazione del processo");
        exit(1);
    }
    else if (pid == 0)
    {
        close(p0p1[0]);
        close(1);
        dup(p0p1[1]);
        close(p0p1[1]);

        execl("/usr/bin/cat", "cat", argv[1], NULL);
        exit(2);
    }

    pipe(p2p0);
    pid = fork();

    if (pid < 0)
    {
        printf("Errore di creazione del processo");
        exit(2);
    }
    else if (pid == 0)
    {
        char carattere;

        close(p2p0[0]);

        while (read(p0p1[0], &carattere, sizeof(carattere)) > 0)
        {
            carattere = tolower(carattere);
            if (carattere == 'a' || carattere == 'e' || carattere == 'i' || carattere == 'o' || carattere == 'u')
            {
                contatoreVocali++;
            }
        }

        write(p2p0[1], &contatoreVocali, sizeof(contatoreVocali));

        exit(0);
    }

    read(p2p0[0], &contatoreVocali, sizeof(contatoreVocali));

    close(p0p1[0]);
    close(p0p1[1]);
    close(p2p0[0]);
    close(p2p0[1]);

    wait(&pid);
    wait(&pid);

    printf("Il file cercato contiene %d vocali.\n", contatoreVocali);

    return 0;
}
