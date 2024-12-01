#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2, pid3;

    pid1 = fork();
    
    if (pid1 < 0) {
        perror("Errore nella creazione del primo figlio");
        exit(1);
    }
    
    if (pid1 == 0) {
        printf("Sono un processo figlio, il mio PID=%d, mio padre ha PID=%d, \"Ciao sono Qui\"\n", getpid(), getppid());
        exit(0);
    }

    pid2 = fork();

    if (pid2 < 0) {
        perror("Errore nella creazione del secondo figlio");
        exit(1);
    }
    
    if (pid2 == 0) {
        printf("Sono un processo figlio, il mio PID=%d, mio padre ha PID=%d, \"Ciao sono Quo\"\n", getpid(), getppid());
        exit(0);
    }


    pid3 = fork();

    if (pid3 < 0) {
        perror("Errore nella creazione del terzo figlio");
        exit(1);
    }
    
    if (pid3 == 0) {
        printf("Sono un processo figlio, il mio PID=%d, mio padre ha PID=%d, \"Ciao sono Qua\"\n", getpid(), getppid());
        exit(0);
    }

    printf("Sono il processo padre, il mio PID=%d, mio figlio 1 ha PID=%d, mio figlio 2 ha PID=%d, mio figlio 3 ha PID=%d\n", 
            getpid(), pid1, pid2, pid3);
    
    wait(NULL);
    wait(NULL);
    wait(NULL);

    return 0;
}