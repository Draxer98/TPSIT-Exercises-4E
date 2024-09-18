/*Progettare un algoritmo che effettui le seguenti operazioni:
• legga da tastiera una coppia di valori interi A e B con A<B;
• continui a leggere da tastiera una serie di valori interi, terminando 
quando il valore letto è al di fuori dell’intervallo [A, B];
• conteggi la media dei valori letti;
• prima di terminare, stampi il valore calcolato.*/

#include <stdio.h>

int main(){
    int a,b;
    int numero;
    int somma=0,contatore=0;
    double media=0;

    do{
        printf("Inserisci A: ");
        scanf("%d", &a);
        printf("Inserisci B: ");
        scanf("%d", &b);
    }while(a>b);

    do{
        printf("Inserisci un numero: ");
        scanf("%d", &numero);

        if(numero>=a && numero<=b){
        somma=somma + numero;
        contatore++;
        }
    } while(numero>=a && numero<=b);

    media= (double)somma/contatore;

    printf("MEDIA dei numeri inseriti: %.2lf", media);
}