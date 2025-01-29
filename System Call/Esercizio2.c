/*Scrivere un programma in linguaggio C che scriva l'alfabeto su un file
il cui nome deve essere letto da argv[1]*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Errore nell'inserimento");
        exit(0);
    }

    int fd, write;
    char alfabeto[] = {"ABCDEFGHIJKLMNOPQRSVTUWXYZ"};
    fd = open(argv[1], O_WRONLY | O_CREAT, 0644);

    write = (fd, alfabeto, sizeof(alfabeto));

    close(fd);
    return 0;
}