/*Utilizzando le system call open, read, write, close leggere il file rfc1918.txt e stamparlo a video.
Il programa deve essere cosi invocato:
$./a.out rfc1918.txt

Consiglio: leggere un carratere per volta */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
    char buf[128];
    int fd;
    fd = open(argv[1], O_RDONLY);

    ssize_t leggere;

    while((leggere = read(fd, buf, sizeof(buf) - 1)) > 0) {
        buf[leggere] = '\0';
        printf("%s", buf);
    }

    ssize_t scrivere;
    while((scrivere = write(fd, buf, sizeof(buf) - 1)) > 0) {
        buf[scrivere] = '\0';
        printf("%s", buf);
    }

    return 0;
}