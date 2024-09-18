/*Progettare un algoritmo che effettui le seguenti operazioni:

• continui a leggere da tastiera una serie di terne di valori interi A ,
B e C finchè non vengono inseriti dei valori tali per cui A + B < C
• conteggi il numero di volte in cui la differenza tra A e B è pari, dispari, e quando è nulla
• prima di terminare, visualizzi il valore dei valori conteggiati*/

#include <stdio.h>

int main(){

    int a,b,c;
    int pari=0,dispari=0,nullo=0,differenza=0;

    do{
        printf("Inserisci A: ");
        scanf("%d", &a);
        printf("Inserisci B: ");
        scanf("%d", &b);
        printf("Inserisci C: ");
        scanf("%d", &c);

        if((a + b) >= c){
            differenza= a - b;

            if(differenza != 0){
                if(differenza % 2 == 0){
                    pari++;
                } else {
                    dispari++;
                }
            } else {
                nullo++;
            }
        }
    } while((a + b) >= c);

    printf("RISULTATI PARI: %d\n", pari);
    printf("RISULTATI DISPARI: %d\n", dispari);
    printf("RISULTATI NULLI: %d\n", nullo);

    return 0;
}