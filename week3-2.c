#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char naam[100];
    int leeftijd;
} Persoon;

int main() {
    Persoon *personen = NULL;
    int aantal_personen = 0;
    char input[100];

    while (1) {
        // Geheugen voor een nieuwe persoon heralloceren
        personen = realloc(personen, (aantal_personen + 1) * sizeof(Persoon));
        if (personen == NULL) {
            printf("Fout bij geheugenallocatie.\n");
            return 1;
        }

        // Informatie invoeren voor de nieuwe persoon
        printf("Voer de naam van de persoon in: ");
        fgets(personen[aantal_personen].naam, sizeof(personen[aantal_personen].naam), stdin);
        // Verwijder de newline karakters die door fgets toegevoegd worden
        personen[aantal_personen].naam[strcspn(personen[aantal_personen].naam, "\n")] = '\0';

        printf("Voer de leeftijd van %s in: ", personen[aantal_personen].naam);
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%d", &personen[aantal_personen].leeftijd);

        aantal_personen++;

        // Alle informatie van alle personen afdrukken
        printf("\nGegevens van alle personen:\n");
        for (int i = 0; i < aantal_personen; i++) {
            printf("Naam: %s, Leeftijd: %d\n", personen[i].naam, personen[i].leeftijd);
        }

        // Vraag of de gebruiker nog een persoon wil toevoegen
        printf("\nWilt u nog een persoon toevoegen? (ja/nee): ");
        fgets(input, sizeof(input), stdin);
        if (strncmp(input, "nee", 3) == 0) {
            break;
        }
    }

    // Geheugen vrijgeven
    free(personen);

    return 0;
}
