#include <stdio.h>
#include <string.h>

int main() {
    // Buffer om de zin van de gebruiker op te slaan
    char sentence[256];

    // Vraag de gebruiker om een zin
    printf("Voer een zin in: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Bereken de lengte van de ingevoerde zin (exclusief de newline)
    size_t length = strlen(sentence);
    if (sentence[length - 1] == '\n') {
        sentence[length - 1] = '\0'; // Verwijder newline character
        length--;
    }

    // Print de lengte van de zin
    printf("De lengte van de ingevoerde zin is: %zu characters\n", length);

    return 0;
}
