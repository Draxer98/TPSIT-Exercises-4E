/*Dato N un numero intero positivo maggiore di 1, generare e visualizzare
il numero precedente.*/

#include <stdio.h>

int main(int argc, char *argv){
    int n;
    
    do{
        printf("Inserisci un numero positivo: ");
        scanf("%d", &n);
    } while(n<0);
    
    for(int i=n; i>-1; i--){
        printf("%d ", i);
    }
    
    
    
    return 0;
}