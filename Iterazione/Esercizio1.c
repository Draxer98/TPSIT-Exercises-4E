/*Dato N un numero intero positivo, generare e visualizzare il numero 
successivo.*/

#include <stdio.h>

int main(int argc, char *argv[]){
    int n,successivo=0;

    do
    {
        printf("Inserisci un numero positivo: ");
        scanf("%d", &n);
    } while (n < 0);

    successivo=n+1;

    printf("Il numero successivo: %d", successivo);
    return 0;
}