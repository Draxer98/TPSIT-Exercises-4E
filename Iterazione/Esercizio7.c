/*Dato N un numero intero positivo maggiore di 1, generare e visualizzare
il numero precedente.*/

#include <stdio.h>

int main(int argc, char *argv){
    int n;
    
    do{
        printf("Inserisci un numeropositivo maggiore di 1: ");
        scanf("%d", &n);
    } while(n<2);
    
    printf("Numero precedente: %d", n-1);
    
    
    
    return 0;
}