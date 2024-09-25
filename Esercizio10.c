/*Una birreria a fine serata deve conteggiare l’incasso. La cassiera accende il software gestionale il quale le chiede di inserire una alla volta le consumazioni servite.
Le consumazioni si dividono in bevande e ristorazione. La cassiera per ogni consumazione deve inserire la tipologia di consumazione e il suo importo.

Quando la cassiera inserisce la stringa “esci” il software deve mostrare a video le seguenti informazioni:
1.	La media dell’incasso delle bevande
2.	La media dell’incasso della ristorazione
3.	Deve indicare se sono state vendute più bevande o più ristorazioni*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char tipologia[12];
    double mediaBevande, mediaRistorazione, incasso;
    double sommaBevande = 0, sommaRistorazione = 0;
    int contatoreBevande = 0, contatoreRistorazione = 0;

    do
    {
        do
        {
            printf("Inserire consumazione (bevande - ristorazione): ");
            scanf("%s", tipologia);
        } while (strcmp("esci", tipologia) != 0 && strcmp(tipologia, "bevande") != 0 && strcmp(tipologia, "ristorazione") != 0);

        if (strcmp(tipologia, "bevande") == 0)
        {
            printf("Inserisci l'incasso: ");
            scanf("%lf", &incasso);

            sommaBevande = sommaBevande + incasso;
            contatoreBevande++;
        }

        if (strcmp(tipologia, "ristorazione") == 0)
        {
            printf("Inserisci l'incasso: ");
            scanf("%lf", &incasso);

            sommaRistorazione = sommaRistorazione + incasso;
            contatoreRistorazione++;
        }
    } while (strcmp("esci", tipologia) != 0);

    mediaBevande = sommaBevande / contatoreBevande;
    mediaRistorazione = sommaRistorazione / contatoreRistorazione;

    printf("Media bevande: %.3lf\n\n", mediaBevande);
    printf("Media ristorazione: %.3lf\n\n", mediaRistorazione);

    if (contatoreBevande == contatoreRistorazione)
    {
        printf("Sono state vendute ugualmente bevande e ristorazioni");
    }
    else
    {
        if (contatoreBevande > contatoreRistorazione)
        {
            printf("Sono state vendute più bevande");
        }
        else
        {
            printf("Sono state vendute più ristorazioni");
        }
    }
}