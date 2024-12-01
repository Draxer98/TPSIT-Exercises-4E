#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("Errore nella creazione del processo");
        exit(1);
    }

    if (pid == 0) {
        printf("Figlio: Mio PID = %d, PID del padre = %d\n", getpid(), getppid());
        for (int i = 0; i < 10; i++) {
            printf("Figlio: %d\n", i);
        }
        exit(0);
    } else {
        printf("Padre: Mio PID = %d, PID del figlio = %d\n", getpid(), pid);
        for (int i = 0; i < 20; i++) {
            printf("Padre: %d\n", i);
        }
        wait(NULL);
    }

    return 0;
}
