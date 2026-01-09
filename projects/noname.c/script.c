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


// START
//    |
//    v
// Exibe menu principal:
// 1. Converters
// 2. Games
// 3. Calculators
//    |
//    v
// Lê input do usuário
//    |
//    v
// Input válido?
//  /   \
// No    Yes
//  |      |
// "Invalid input"  Converte input para program_type
// Retorna 1         |
//                  v
//          program_type válido? (1-3)
//              /        \
//            No          Yes
//             |           |
//      "Invalid option"   Chama subMenu(program_type)
//      Retorna 1           |
//                          v
//                  Exibe submenu do tipo escolhido
//                          |
//                          v
//                  Lê escolha do programa
//                          |
//                          v
//                Input do programa válido? (1-2)
//                      /       \
//                    No         Yes
//                     |           |
//            "Invalid option"     switch(program_type)
//            Retorna 1          /      |       \
//                                |      |       |
//                        Converters  Games  Calculators
//                            |         |       |
//                    Chama convertersProgram  ...
//                            |
//                          END
int main()
{
    programType program_type = 0;
    int program = 0;
    int input = 0;

    printf("Choose a type of program (1-3):\n");
    printf("1. Converters\n");
    printf("2. Games\n");
    printf("3. Calculators\n\n");

    if (scanf("%d", &input) != 1)
    {
        printf("Invalid input.\n");
        while (getchar() != '\n');
        return 1;
    }

    program_type = (programType)input;

    if (program_type < Converters || program_type > Calculators)
    {
        printf("Invalid option. Try again.\n");
        return 1;
    }

    subMenu(program_type);

    printf("Choose a program:\n");

    if (scanf("%d", &program) != 1)
    {
        printf("Invalid input.\n");
        while (getchar() != '\n');
        return 1;
    }

    if (program < 1 || program > 2)
    {
        printf("Invalid option. Try again.\n");
        return 1;
    }

    switch (program_type)
    {
        case Converters:
            convertersProgram((convertersPrograms)program);
            break;

        case Games:
            gamesProgram((gamesPrograms)program);
            break;

        case Calculators:
            calculatorProgram((calculatorPrograms)program);
            break;
    }

    return 0;
}