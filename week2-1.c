#include <stdio.h>

// Functie die de grotere waarde van twee arrays vergelijkt en in een derde array plaatst
void maxArrays(float *array1, float *array2, float *array3, int length) {
    for (int i = 0; i < length; i++) {
        array3[i] = (array1[i] > array2[i]) ? array1[i] : array2[i];
    }
}

int main() {
    // Arrays initialiseren
    float array1[] = {0.7, 3.3, 0.5, 10.3};
    float array2[] = {4.1, 1.5, 0.5, 2.3};
    int length = sizeof(array1) / sizeof(array1[0]);
    float array3[length];

    // Print de waarden van array1 en array2
    printf("Array 1: ");
    for (int i = 0; i < length; i++) {
        printf("%.1f ", array1[i]);
    }
    printf("\n");

    printf("Array 2: ");
    for (int i = 0; i < length; i++) {
        printf("%.1f ", array2[i]);
    }
    printf("\n");

    // Roep de functie maxArrays aan
    maxArrays(array1, array2, array3, length);

    // Print de waarden van array3
    printf("Array 3: ");
    for (int i = 0; i < length; i++) {
        printf("%.1f ", array3[i]);
    }
    printf("\n");

    return 0;
}
