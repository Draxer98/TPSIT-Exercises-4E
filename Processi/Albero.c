#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int p2 = fork();
    if (p2 < 0)
    {
        printf("Errore nella creazione del processo");
        exit(0);
    }
    else if (p2 == 0)
    {
        printf("Sono il figlio p2: %d\n", getpid());
        int p4 = fork();
        if (p4 < 0)
        {
            printf("Errore nella creazione del processo");
        }
        else if (p4 == 0)
        {
            printf("Sono il processo figlio di p2, ovvero p4: %d\n", getpid());
            exit(0);
        }
        wait(NULL);
        exit(0);
    }

    int p3 = fork();
    if (p3 < 0)
    {
        printf("Errore nella creazione del processo");
        exit(0);
    }
    else if (p3 == 0)
    {
        printf("Sono il figlio p3: %d\n", getpid());
        int p5 = fork();
        if (p5 < 0)
        {
            printf("Errore nella creazione del processo");
        }
        else if (p5 == 0)
        {
            printf("Sono il processo figlio di p3, ovvero p5: %d\n", getpid());
            exit(0);
        }
        
        int p6 = fork();
        if (p6 < 0)
        {
            printf("Errore nella creazione del processo");
        }
        else if (p6 == 0)
        {
            printf("Sono il processo figlio di p3, ovvero p6: %d\n", getpid());
            exit(0);
        }
        wait(NULL);
        wait(NULL);
        exit(0);
    }

    wait(NULL);
    wait(NULL);

    return 0;
}
