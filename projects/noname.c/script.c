#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef enum
{
    Converters,
    Games,
    Calculators
} Choice;

int switch_func(int program_type)
{
    switch (program_type)
    {
        case 1:
            printf("Converters\n");
            break;

        case 2:
            printf("Games\n");
            break;
    
        case 3:
            printf("Calculators\n");
            break;

        default:
            printf("Please choose a valid type of program (1-3):\n ");
            break;
    }
    return program_type;
}

int main()
{
    int program_type = 0;

    printf("Choose a type of program (1-3):\n");

    printf("1. Converters\n");
    printf("2. Games\n");
    printf("3. Calculators\n\n");
    scanf("%d", &program_type);

    switch_func(program_type);

    return 0;
}