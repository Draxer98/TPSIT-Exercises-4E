/*Progettare un algoritmo che risolva il seguente problema. Si richieda 
all’utente di inserire una serie di terne di dati numerici (A, B, C). 
Il programma deve terminare quando uno dei valori inseriti è minore di
zero. Si scartino le terne nelle quali i valori non sono in ordine
strettamente crescente, ovvero quelle terne per cui non valga A < B < C.
Su tutte le terne non scartate si calcoli il massimo e il minimo dei
valori inseriti. Si stampino a video tali valori massimi e minimi prima
di terminare il programma.*/

#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv[]){
    int a,b,c;
    int min=INT_MAX, max=0;

    do{
        printf("Inserisci A: ");
        scanf("%d", &a);
        printf("Inserisci B: ");
        scanf("%d", &b);
        printf("Inserisci C: ");
        scanf("%d", &c);

        if(a<0 || b<0 || c<0){
            break;
        }

        if(a<b && b<c){
            if(a<min){
                min=a;
            }

            if(c>max){
                max=c;
            }
        } else {
            printf("Terna non valida, riprova\n");
        }
    } while(a>0 && b>0 && c>0);

    printf("MIN: %d\n", min);
    printf("MAX: %d", max);
}