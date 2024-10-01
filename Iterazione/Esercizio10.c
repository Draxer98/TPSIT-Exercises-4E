/*Dato N un numero intero positivo, calcolare e visualizzare la somma dei
primi N numeri interi. */

#include <stdio.h>

int main(int argc, char *argv[]){
    int n, i=0;
    int somma=0;
    
    do{
        printf("Inserisci un numero positivo: ");
        scanf("%d", &n);
    } while(n<0);
    
    i = n;
    
    while(i>0){
        somma=somma+i;
        i--;
    }
    
    printf("Somma dei numeri precedenti: %d", somma);
    return 0;
}