/*Scrivere un programma in linguaggio C che usa il comando 
della shell rm per eliminare tutti files presenti
nell'intervallo [argv[1], argv[argc-1]]

esempio:
$ ./a.out /tmp/1.txt /tmp/3.txt /tmp/2.txt*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc < 1)
    {
        printf("Errore nell'i9nserimento");
        exit(1);
    }

    int pid[argc - 2];
    for (int i = 1; i < argc; i++)
    {
        pids[i - 1] = fork();
        if (pid[i - 1] == 0)
        {
            execl("/usr/bin/rm", "rm", argv[i], NULL);
            printf("Exec ha terminato con errori");
            exit(2);
        }
    }

    for (int i = 0; i < argc - 2; i++)
    {
        wait(&pid[i]);
    }

    return 0;
}