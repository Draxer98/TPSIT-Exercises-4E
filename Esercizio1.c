/*Esercizio 1
Progettare un algoritmo che effettui la lettura da tastiera di una serie di coppie di valori numerici.
L’algoritmo deve calcolare e stampare il rapporto tra il valore minore e quello maggiore dei due. Il
programma termina quando uno dei due valori o entrambi sono uguali a zero.*/

#include <stdio.h>

int main(){
    int numero1, numero2;
    double rapporto=0;
    
    do{
        printf("Inserisci il primo numero: ");
        scanf("%d", &numero1);

        printf("Inserisci il primo numero: ");
        scanf("%d", &numero2);

        if(numero1!=0 && numero2!=0){
            if(numero1>=numero2){
                rapporto=(double)numero1/numero2;
            } else {
                rapporto=(double)numero2/numero1;
            }
            
            printf("Rapporto tra i due numeri: %.2lf\n\n", rapporto);
        }

        
    } while(numero1!=0 && numero2!=0);

    printf("\nProgramma terminato");
    
    return 0;
}