/*Dati due numeri si scriva in linguaggio C una funzione di tipo void denominata scambia,
che dati in input 2 numeri li scambi.*/

#include <stdio.h>

void scambia(int *a, int *b)
{

    int scambio = 0;
    scambio = *a;
    *a = *b;
    *b = scambio;
}

int main(int argc, char *argv[])
{

    int a = 10, b = 20;

    scambia(&a, &b);

    printf("A: %d\n", a);
    printf("B: %d", b);

    return 0;
}