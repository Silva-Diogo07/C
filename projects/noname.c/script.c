#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

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

void gamesProgram(gamesPrograms program, int *tries, int *secret)
{
    switch (program)
    {
        case GN:
            play(tries, secret);
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

void secret_number(int *secret)
{
    int max = 0;

    printf("Enter the max number: ");
    if (scanf("%d", &max) != 1 || max <= 0)
    {
        printf("Invalid max number.\n");
        return;
    }

    *secret = (rand() % max) + 1;
}

void ask_for_trys(int *tries)
{
    printf("Enter how many trys you want: ");
    scanf("%d", tries);
}

void ask_for_guess(int *guess)
{
    printf("What's your guess? ");
    scanf("%d", guess);
}

bool check_guess(int *guess, int *secret, int *tries)
{
    if (*guess > *secret)
    {
        printf("Lower\n");
        (*tries)--;
        return false;
    }
    else if (*guess < *secret)
    {
        printf("Higher\n");
        (*tries)--;
        return false;
    }
    else
    {
        printf("You guessed right!\n");
        return true;
    }
}

void play(int *tries, int *secret)
{
    int guess;

    ask_for_trys(tries);
    secret_number(secret);

    do
    {
        ask_for_guess(&guess);
    }
    while (!check_guess(&guess, secret, tries) && *tries > 0);

    if (*tries == 0)
    {
        printf("You LOST!\n");
    }
}

int main()
{
    srand(time(NULL));

    programType program_type = 0;
    int program = 0;
    int input = 0;

    int tries = 0;
    int secret = 0;

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
            gamesProgram((gamesPrograms)program, &tries, &secret);
            break;

        case Calculators:
            calculatorProgram((calculatorPrograms)program);
            break;
    }

    return 0;
}
