#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef enum
{
    Converters = 1,
    Games,
    Calculators
} programType;

typedef enum
{
    tempConverter = 1,
    weightConverter
} convertersPrograms;

typedef enum
{
    GN = 1,
    RPS
} gamesPrograms;

typedef enum
{
    circleCalculator = 1,
    compundCalculator
} calculatorPrograms;

void subMenu(programType program_type)
{
    switch (program_type)
    {
        case Converters:
            printf("Converters:\n");
            printf("1. Temperature Converter\n");
            printf("2. Weight Converter\n");
            break;

        case Games:
            printf("Games:\n");
            printf("1. Guess the Number\n");
            printf("2. Rock Paper Scissors\n");
            break;
    
        case Calculators:
            printf("Calculators:\n");
            printf("1. Circle Calculator\n");
            printf("2. Compound Interest Calculator\n");
            break;

        default:
            printf("Invalid option. Try again.\n");
            break;
    }
}

void convertersProgram(convertersPrograms program)
{
    switch (program)
    {
        case tempConverter:
            printf("Hot Food\n");
            break;
        
        case weightConverter:
            printf("Heavy Food\n");
            break;

        default:
            printf("Invalid option. Try again.\n");
            break;
    }
        
}   

void gamesProgram(gamesPrograms program)
{
    switch (program)
    {
        case GN:
            printf("Guess the number\n");
            break;

        case RPS:
            printf("Rock Paper Scissors\n");
            break;

        default:
            printf("Invalid option. Try again.\n");
            break;
    }
}

void calculatorProgram(calculatorPrograms program)
{
    switch (program)
    {
        case circleCalculator:
            printf("Circle Calculator Program\n");
            break;

        case compundCalculator:
            printf("Compound Interest Calculator Program\n");
            break;

        default:
            printf("Invalid option. Try again.\n");
            break;
    }
}

int main()
{
    int program_type = 0;
    int program = 0;

    printf("Choose a type of program (1-3):\n");

    printf("1. Converters\n");
    printf("2. Games\n");
    printf("3. Calculators\n\n");
    scanf("%d", &program_type);
    
    subMenu(program_type);

    printf("Choose a program:\n");
    scanf("%d", &program);

    if (program_type == 1)
    {
        convertersProgram(program);
    }
    else if (program_type == 2)
    {
        gamesProgram(program);
    }
    else if (program_type == 3)
    {
        calculatorProgram(program);
    }
    else
    {
        printf("Invalid option. Try again\n");
        return 1;        
    }

    return 0;
}