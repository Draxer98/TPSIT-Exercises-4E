/*Scrivere un programma in linguaggio C dove il processo figlio manda una stringa
al processo padre e quest'ultimo lo stampa a video.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int pid;
    int p0p1[2];
    char buffer[60];

    pipe(p0p1);

    pid = fork();

    if(pid == 0){
        char stringa[] = {"Ciao Padre!"};

        close(p0p1[0]);

        write(p0p1[1], stringa, sizeof(stringa));

        exit(0);
    }

    close(p0p1[1]);

    read(p0p1[1], buffer, sizeof(buffer));

    printf("PADRE: Messaggio del figlio = %s", buffer);

    return 0;
}