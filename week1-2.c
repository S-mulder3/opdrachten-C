#include <stdio.h>

void print_function(char letter);

int main(void)
{
    char star = '*';
    char dash = '-';
    int ctr; // Declaring a local variable for this loop
    for (ctr = 0; ctr < 10; ctr++)
    {
        print_function(star);
        print_function(dash);
        printf("\n");
    }
    return 0;
}

void print_function(char letter)
{
    int inner_ctr; // Use a separate counter variable
    for (inner_ctr = 0; inner_ctr < 10; inner_ctr++) // Loop for 10 characters
    {
        printf("%c", letter);
    }
}
