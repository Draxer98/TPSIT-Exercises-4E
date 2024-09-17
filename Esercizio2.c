/*Progettare un algoritmo che effettui le seguenti operazioni:
• continui a leggere da tastiera due valori numerici, fermandosi quando uno dei due numeri è
0 (zero)
• per ogni coppia di numeri letti:
◦ calcoli il prodotto dei due numeri e ne stampi il valore
◦ sommi il prodotto calcolato ad una variabile che memorizzi la somma di tutti i prodotti
• all’uscita del ciclo, stampi il valore della somma*/

#include <stdio.h>

int main(){
    int numero1, numero2;
    int prodotto=0;
    int somma=0;
    
    do{
        printf("Inserisci il primo numero: ");
        scanf("%d", &numero1);

        printf("Inserisci il primo numero: ");
        scanf("%d", &numero2);

        if(numero1!=0 && numero2!=0){
            prodotto=numero1 * numero2;
            printf("Prodotto tra i due numeri: %d\n\n", prodotto);
            somma=somma + prodotto;
        }

        
    } while(numero1!=0 && numero2!=0);

    printf("La somma di tutti i prodotti: %d\n", somma);
    printf("\nProgramma terminato");
    
    return 0;
}