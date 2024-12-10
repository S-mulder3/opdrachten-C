#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void copy_and_shift(FILE *source, FILE *destination) {
    char ch;

    while ((ch = fgetc(source)) != EOF) {
        // Skip niet-zichtbare karakters (LF, EOF)
        if (ch == '\n' || ch == EOF) {
            fputc(ch, destination);
        } else {
            // Verhoog de ASCII-waarde van elk karakter met 1
            ch = (char)(ch + 1);
            fputc(ch, destination);
        }
    }
}

int count_visible_characters(FILE *file) {
    int count = 0;
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        // Tel alleen zichtbare karakters
        if (ch != '\n' && ch != EOF) {
            count++;
        }
    }
    return count;
}

int main() {
    FILE *sourceFile, *destFile;
    char sourceFileName[100], destFileName[100];

    // Vraag de gebruiker om de bestandsnaam in te voeren
    printf("Voer de naam van het bronbestand in (bijv. bestand.txt): ");
    scanf("%s", sourceFileName);

    // Open het bronbestand voor lezen
    sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        perror("Fout bij openen van het bronbestand");
        return 1;
    }

    // Vraag om de naam van het nieuwe bestand
    printf("Voer de naam van het doelbestand in (bijv. kopie.txt): ");
    scanf("%s", destFileName);

    // Open het doelbestand voor schrijven
    destFile = fopen(destFileName, "w");
    if (destFile == NULL) {
        perror("Fout bij openen van het doelbestand");
        fclose(sourceFile);
        return 1;
    }

    // Tel het aantal zichtbare karakters
    int visibleCharCount = count_visible_characters(sourceFile);
    printf("Aantal zichtbare karakters in het bestand: %d\n", visibleCharCount);

    // Zet de file pointer terug naar het begin van het bestand
    rewind(sourceFile);

    // Kopieer de inhoud naar het nieuwe bestand met ASCII-shift
    copy_and_shift(sourceFile, destFile);

    // Sluit beide bestanden
    fclose(sourceFile);
    fclose(destFile);

    printf("Bestand is succesvol gekopieerd en de ASCII-waarden zijn verschoven.\n");

    return 0;
}
