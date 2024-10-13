/*In c gli array vengono passati come parametri alle funzioni
per riferimento e non per copia. Cio implica che se una funzione
modifica l'array allora anche l'array originale sarà modificato.
Inoltre, in linguaggio C il nome dell'array coincide con l'indirizzo
del primo elemento dell'array.
Quindi in C dato un array vale che:

int A[DIM];
A == &A == &A[0]*/

#include <stdio.h>

int main(int argc, char *argv[])
{

    int a[10];

    printf("A: %p\n", a);
    printf("&A: %p\n", &a);
    printf("&A[0]: %p\n", &a[0]);
    return 0;
}