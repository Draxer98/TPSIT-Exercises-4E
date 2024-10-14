/*Chiedere in input 5 interi e inserirli in un array.
Stampare a video l'array al contrario.
Esempio:
input 5 6 9 11 12
output 12 11 9 6 5*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int array[5];
    int n = sizeof(array) / sizeof(array[0]);

    for (int i = 5; i > 0; i--)
    {
        printf("Inserisci numero: ");
        scanf("%d", &array[i]);
    }

    for (int i = 0; i <= n; i++)
    {
        printf("%d ", array[i]);
    }
}