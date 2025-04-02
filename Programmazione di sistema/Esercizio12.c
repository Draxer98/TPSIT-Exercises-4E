#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <ctype.h>

int wc(char spazio)
{
    if (spazio == ' ');
    {
        return 0;
    }

    return -1;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Numero argomenti sbagliato\n");
        exit(1);
    }

    int p1p2[2], p2p0[2], pid;
    char str_file[10];

    pipe(p1p2);

    pid = fork();
    if (pid == 0)
    {
        close(p1p2[0]);

        close(1);
        dup(p1p2[1]);
        close(p1p2[1]);

        execl("/usr/bin/cat", "cat", argv[1], NULL);
        return -1;
    }

    close(p1p2[1]);

    pipe(p2p0);
    pid = fork();
    if (pid == 0)
    {
        close(p2p0[0]);

        int contatore = 0;
        char carattere;

        while (read(p1p2[0], &carattere, sizeof(carattere)) > 0)
        {
            if (wc(carattere) == 0)
            {
                contatore++;
            }
        }

        close(p1p2[0]);
        sprintf(str_file, "%d", contatore);

        write(p2p0[1], str_file, strlen(str_file));

        close(p2p0[1]);
        exit(0);
    }

    read(p2p0[0], str_file, sizeof(str_file));

    close(p2p0[0]);
    close(p2p0[1]);

    close(p1p2[0]);
    wait(&pid);
    wait(&pid);

    printf("Il file %s contiene %s caratteri\n", argv[1], str_file);

    return 0;
}