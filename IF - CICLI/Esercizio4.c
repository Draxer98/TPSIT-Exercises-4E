/*Progettare un algoritmo che effettui la lettura da tastiera di una serie
di coppie di valori numerici reali (sia positivi che negativi che zero).
Per ciascuna coppia, l’algoritmo deve calcolare e stampare il valore
della radice quadrata del rapporto tra il valore maggiore e quello
minore dei due. Il programma termina quando vengono inseriti dei valori
che non permettono di svolgere il calcolo nel dominio dei numeri reali.
Prima di terminare si richiede di stampare un messaggio che indichi la
ragione per cui non è stato possibile svolgere il calcolo.*/

#include <stdio.h>
#include <math.h>

int main(){
    int numero1, numero2;
    double risultato=0;
    int esistenza;
    
    do{
        printf("Inserisci il primo numero: ");
        scanf("%d", &numero1);

        printf("Inserisci il primo numero: ");
        scanf("%d", &numero2);

        if(numero2!=0){
            risultato=sqrt((double)numero1/numero2);
                    
            if(risultato>=0){
            printf("Rapporto tra i due numeri: %.2lf\n\n", risultato);
            } else {
                    esistenza = 1;
            } 
        } else {
            esistenza=2;
            break;
        }
        
    } while(esistenza!=1 && esistenza!=2);

    if(esistenza==1 && esistenza!=0){
        printf("Il risultato è impossibile perchè la radice quadrata di un numero è sempre positiva");
    } else {
        printf("Il risltato è impossibile perchè non si può dividere un numero per 0");
    }
}