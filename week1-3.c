#include <stdio.h>
#include "print_function.h" // Headerbestand voor de print_function

int main() {
    int keuze;

    while (1) {
        printf("\nMaak een keuze:\n");
        printf("1. Optie 1\n");
        printf("2. Optie 2\n");
        printf("3. Roep print_function() aan\n");
        printf("Typ een negatief getal om te stoppen.\n");
        printf("Keuze: ");
        scanf("%d", &keuze);

        if (keuze < 0) {
            printf("Programma gestopt.\n");
            break;
        }

        switch (keuze) {
            case 1:
                printf("Je hebt Optie 1 gekozen.\n");
                break;
            case 2:
                printf("Je hebt Optie 2 gekozen.\n");
                break;
            case 3:
                printf("Je hebt gekozen om print_function() aan te roepen:\n");
                print_function();
                break;
            default:
                printf("Ongeldige keuze. Probeer opnieuw.\n");
        }
    }

    return 0;
}
