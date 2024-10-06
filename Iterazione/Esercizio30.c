/*Dati due numeri interi positivi N1 e N2, verificare se N1 è il quadrato
di N2. */

#include <stdio.h>

int main(int argc, char *argv[])
{
    int a, b;

    do
    {
        printf("Inserire il primo intero positivo: ");
        scanf("%d", &a);
        printf("Inserire il secondo intero positivo: ");
        scanf("%d", &b);
    } while (a < 0 && b < 0);

    if (b == a ^ 2)
    {
        printf("Il primo numero è il quadrato del secondo");
    }
    else
    {
        printf("Il primo numero non è il quadrato del secondo");
    }

    return 0;
}