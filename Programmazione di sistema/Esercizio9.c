/*Si vuole realizzare un software concorrente in linguaggio C che si occupi di
copiare un file da un path ad un altro path utilizzando la seguente invocazione:

$ ./cp file.txt copy.txt

Il software deve essere cosi organizzato:
P0 genera il processo p1 che legge il file.txt e invia il suo
contenuto al processo P2
P0 genera P2 che riceve il contenuto del file.txt e lo scrive nel file copy.txt

Osservazione:
1) Il programmatore decida autonomamente la modalità di lettura del file.txt
scegliendo la system call più idonea.
2) Si usi argv

esempio di utilizzo:
$ ./cp file.txt copy.txt

$ cat file.txt
AB123 pagato 20,00
AB123 insoluto 120,00
AC123 insoluto 120,00
AC123 insoluto 100,00

$ cat copy.txt
AB123 pagato 20,00
AB123 insoluto 120,00
AC123 insoluto 120,00
AC123 insoluto 100,00*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Errore nell'inserimento");
        exit(1);
    }
    int pid, p1p2[2], fd;
    char buffer[100];

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
        int nread;

        close(1);
        fd = open(argv[2], O_WRONLY, 0644);

        while (nread = read(p1p2[0], &buffer, sizeof(buffer)) > 0)
        {
            write(fd, &buffer, nread);
        }

        exit(1);
    }

    close(p1p2[0]);

    wait(&pid);
    wait(&pid);

    return 0;
}