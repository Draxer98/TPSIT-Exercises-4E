/*Realizzare il comando cat file.txt | sort in linguaggio C utilizzando
le pipe e la programmazione concorrente

Osservazione:
P0 generi P1 e successivamente generi P2*/

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

    pid = fork();

    if (pid == 0)
    {
        close(0);
        dup(p1p2[0]);
        close(p1p2[0]);

        execl("/usr/bin/sort", "sort", NULL);
        return -1;
    }

    close(p1p2[0]);

    wait(&pid);
    wait(&pid);

    return 0;
}