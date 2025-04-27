/*Un’applicazione multiprocesso in C deve presentare la seguente interfaccia:
controlloFatture nomeFileFatture
dove nomeFileFatture è un nome assoluto di file.

A questo fine, l’addetto dell’azienda deve verificare, sul file passato
come parametro, se un cliente ha ancora delle fatture in sospeso oppure se
le ha pagate tutte.

Nel file passato come parametro sono memorizzate tutte le fatture, una per
ogni riga. Ogni riga è composta dal nome del cliente (un codice di 5 caratteri
alfanumerico che identifica univocamente ogni cliente), da un campo che
contiene la stringa “pagato” per le fatture saldate oppure “insoluto”
per quelle ancora insolute, più altri campi con altre informazioni.

L’addetto dell’azienda inserisce a terminale il codice dei clienti (uno alla
volta) di cui vuole controllare lo stato dei pagamenti. Per ogni cliente
inserito, l’applicazione deve visualizzare il nome del cliente stesso e il
numero di fatture di tale cliente che risultano ancora da pagare.

Quando l’applicazione termina,a causa dell’inserimento della stringa “esci”,
il programma deve visualizzare il numero totale di richieste di servizio
eseguite fino a quel momento.*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Errore nell'inserimento");
        exit(0);
    }

    int pid, p0p1[2], richiesteServizio;
    char stringa[100], buffer[100];

    while (1)
    {
        pipe(p0p1);

        printf("Inserisci codice: ");
        scanf("%s", stringa);

        if (strcmp(stringa, "esci") == 0)
        {
            printf("Richieste efeguite: %d", richiesteServizio);
            exit(1);
        }

        pid = fork();

        if (pid == 0)
        {
            close(p0p1[0]);
            close(1);
            dup(p0p1[1]);
            close(p0p1[1]);

            execl("/usr/bin/grep", "grep", "-c", strcat(stringa, "insoluto"), argv[1], NULL);
            return -1;
        }

        close(p0p1[1]);

        read(p0p1[0], &buffer, sizeof(buffer));
        printf("Il codice %s ha %d fatture da pagare \n", stringa, atoi(buffer));
        close(p0p1[0]);

        richiesteServizio++;
    }

    return 0;
}