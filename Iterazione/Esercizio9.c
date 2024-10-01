/*Dati due numeri interi e positivi N1 e N2 con N2>N1, generare e
visualizzare in ordine decrescente i numeri compresi tra N1 e N2. */

#include <stdio.h>

int main(int argc, char *argv){
    int a,b;
    
    do{
        printf("Inserisci il primo numero: ");
        scanf("%d", &a);
        printf("Inserisci il secondo numero: ");
        scanf("%d", &b);
    } while(a<0 && b<0 && a>b);
    
    for(int i=b; i>=a; i--){
        printf("%d ", i);
    }
    
    
    
    return 0;
}