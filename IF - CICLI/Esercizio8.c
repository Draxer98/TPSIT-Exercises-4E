/*Progettare un algoritmo che risolve il seguente problema. Si desidera 
calcolare la somma delle radici quadrate di N valori numerici inseriti 
dall’utente, con N inserito in input. 
L’algoritmo deve stampare la somma calcolata. L’algoritmo deve terminare
con un messaggio di errore quando viene inserito un numero che non
permette di effettuare il calcolo (nel dominio dei numeri reali).*/

#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]){
    int quantita, numero;
    double somma=0;
    int esistenza=0;

    do{
        printf("Numeri da inserire: ");
        scanf("%d", &quantita);
    } while(quantita<1);

    for(int i=0; i<quantita; i++){
        printf("Inserisci %d° numero: ", i+1);
        scanf("%d", &numero);
        if(numero<0){
            printf("numero non disponibile perchè non rispetta il dominio\n");
        } else {
            somma = somma + sqrt(numero);
        }
    }

    printf("La somma delle radici quadrate dei numeri: %.3lf", somma);
}