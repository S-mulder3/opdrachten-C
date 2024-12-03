#include <stdio.h>
#include <string.h> // Voor strlen

// Defineer de struct "opleiding"
struct opleiding {
    char naamOpleiding[50];
    int instroomJaar;
};

// Defineer de struct "student"
struct student {
    char naam[50];
    int leeftijd;
    struct opleiding opleidingInfo;
};

int main() {
    struct student studenten[3];

    for (int i = 0; i < 3; i++) {
        printf("Student %d:\n", i + 1);

        // Vraag de naam van de student
        printf("  Voer de naam van de student in: ");
        fgets(studenten[i].naam, sizeof(studenten[i].naam), stdin);
        if (studenten[i].naam[strlen(studenten[i].naam) - 1] == '\n') {
            studenten[i].naam[strlen(studenten[i].naam) - 1] = '\0';
        }

        // Vraag de leeftijd van de student
        printf("  Voer de leeftijd van de student in: ");
        scanf("%d", &studenten[i].leeftijd);
        getchar(); // Verwijder de newline uit de inputbuffer

        // Vraag de naam van de opleiding
        printf("  Voer de naam van de opleiding in: ");
        fgets(studenten[i].opleidingInfo.naamOpleiding, sizeof(studenten[i].opleidingInfo.naamOpleiding), stdin);
        if (studenten[i].opleidingInfo.naamOpleiding[strlen(studenten[i].opleidingInfo.naamOpleiding) - 1] == '\n') {
            studenten[i].opleidingInfo.naamOpleiding[strlen(studenten[i].opleidingInfo.naamOpleiding) - 1] = '\0';
        }

        // Vraag het instroomjaar
        printf("  Voer het instroomjaar in: ");
        scanf("%d", &studenten[i].opleidingInfo.instroomJaar);
        getchar(); // Verwijder de newline uit de inputbuffer

        printf("\n");
    }

    // Print de informatie van de studenten
    printf("Informatie van studenten:\n");
    for (int i = 0; i < 3; i++) {
        printf("Student %d:\n", i + 1);
        printf("  Naam: %s\n", studenten[i].naam);
        printf("  Leeftijd: %d\n", studenten[i].leeftijd);
        printf("  Opleiding: %s\n", studenten[i].opleidingInfo.naamOpleiding);
        printf("  Instroomjaar: %d\n\n", studenten[i].opleidingInfo.instroomJaar);
    }

    return 0;
}
