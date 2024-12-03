#include <stdio.h>
#define PI 3.14159

// Functie die de omtrek berekent en via een pointer teruggeeft
void calculate(double diameter, double *circumference) {
    *circumference = PI * diameter; // Bereken omtrek en sla op via de pointer
}

int main() {
    double diameter, circumference;  // Variabele voor diameter en omtrek
    double *ptr_circumference = &circumference;  // Pointer naar de omtrekvariabele

    // Vraag de gebruiker om de diameter
    printf("Voer de diameter van de cirkel in: ");
    scanf("%lf", &diameter);

    // Roep de calculate functie aan
    calculate(diameter, ptr_circumference);

    // Print het resultaat
    printf("De omtrek van de cirkel is: %.2lf\n", circumference);

    return 0;
}
