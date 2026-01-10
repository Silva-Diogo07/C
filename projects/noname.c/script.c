#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void runTemperatureConverter();
void runWeightConverter();

/* ===================== ENUMS ===================== */

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

/* ===================== MENUS ===================== */

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

/* ===================== CONVERTERS ===================== */

void convertersProgram(convertersPrograms program)
{
    switch (program)
    {
        case tempConverter:
            runTemperatureConverter();
            break;

        case weightConverter:
            runWeightConverter();
            break;

        default:
            printf("Invalid option.\n");
            break;
    }
}

/* ===================== GUESS THE NUMBER ===================== */

void secret_number(int *secret)
{
    int max;

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
    printf("Enter how many tries you want: ");
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

    printf("You guessed right!\n");
    return true;
}

bool askPlayAgain(void)
{
    char choice;

    printf("Play again? (y/n): ");
    scanf(" %c", &choice);  // espaço antes do %c é IMPORTANTE

    return (choice == 'y' || choice == 'Y');
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

/* ===================== RUNNERS ===================== */

void runGuessTheNumber(void)
{
    int tries = 0;
    int secret = 0;

    do
    {
        play(&tries, &secret);
    }
    while (askPlayAgain());
}

void runRockPaperScissors(void)
{
    printf("Rock Paper Scissors (not implemented yet)\n");
}

void runTemperatureConverter()
{
    int choice = 0;
    float celcius = 0.0f;
    float fahrenheit = 0.0f;

    printf("1. Celcius to fahrenheit\n");
    printf("2. Fahrenheit to celcius\n");

    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Enter Celcius: ");
        scanf("%f", &celcius);
        fahrenheit = (celcius * 9 / 5) + 32;
        printf("%.1f celcius is equal to %.1f fahrenheit\n", celcius, fahrenheit);
    }
    else if (choice == 2)
    {
        printf("Enter Fahrenheit: ");
        scanf("%f", &fahrenheit);
        celcius = (fahrenheit - 32) * 5 / 9;
        printf("%.1f fahrenheit is equal to %.1f celcius\n", fahrenheit, celcius);
    }
    else
    {
        printf("Invalid choice\n");
    }
}

void runWeightConverter()
{
    int choice = 0;
    float pounds = 0.0f;
    float kilograms = 0.0f;

    printf("1. Kilograms to pounds\n");
    printf("2. Pounds to kilograms\n");

    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Enter Kilograms: ");
        scanf("%f", &kilograms);
        pounds = kilograms * 2.20462;
        printf("%.2f kilograms is equal to %.2f pounds\n", kilograms, pounds);
    }
    else if (choice == 2)
    {
        printf("Enter Pounds: ");
        scanf("%f", &pounds);
        kilograms = pounds / 2.20462;
        printf("%.2f pounds is equal to %.2f kilograms\n", pounds, kilograms);
    }
    else
    {
        printf("Invalid choice\n");
    }
}

void runCircleCalculator()
{
    double radius = 0.0;
    double area = 0.0;
    double surfaceArea = 0.0;
    double volume = 0.0;
    const double PI = 3.14159;

    printf("Enter the radius: ");
    scanf("%lf", &radius);

    area = PI * pow(radius, 2);
    surfaceArea = 4 * PI * pow(radius, 2);
    volume = (4.0 / 3.0) * PI * pow(radius, 3);

    printf("Area: %.2lf\n", area);
    printf("Surface Area: %.2lf\n", surfaceArea);
    printf("Volume: %.2lf\n", volume);
}

void runCompoundCalculator()
{
    double principal = 0.0;
    double interest_rate = 0.0;
    int years = 0;
    int timesCompounded = 0;
    double total = 0.0;

    printf("Enter the initial amount: ");
    scanf("%lf", &principal);

    printf("Enter the interest rate: ");
    scanf("%lf", &interest_rate);

    printf("Enter the number of years: ");
    scanf("%d", &years);

    printf("Enter the number of times compounded per year: ");
    scanf("%d", &timesCompounded);

    total = principal * pow(1 + interest_rate / timesCompounded, timesCompounded * years);

    printf("After %d years the total will be £%.2lf\n", years, total);   
}

/* ===================== GAMES MENU ===================== */

void gamesProgram(gamesPrograms program)
{
    switch (program)
    {
        case GN:
            runGuessTheNumber();
            break;

        case RPS:
            runRockPaperScissors();
            break;

        default:
            printf("Invalid option.\n");
            break;
    }
}

/* ===================== CALCULATORS ===================== */

void calculatorProgram(calculatorPrograms program)
{
    switch (program)
    {
        case circleCalculator:
            runCircleCalculator();
            break;

        case compundCalculator:
            printf("Compound Interest Calculator (not implemented yet)\n");
            break;

        default:
            printf("Invalid option.\n");
            break;
    }
}

/* ===================== MAIN ===================== */

int main()
{
    srand(time(NULL));

    programType program_type;
    int program;
    int input;

    printf("Choose a type of program (1-3):\n");
    printf("1. Converters\n");
    printf("2. Games\n");
    printf("3. Calculators\n\n");

    if (scanf("%d", &input) != 1)
    {
        printf("Invalid input.\n");
        return 1;
    }

    program_type = (programType)input;

    if (program_type < Converters || program_type > Calculators)
    {
        printf("Invalid option.\n");
        return 1;
    }

    subMenu(program_type);

    printf("Choose a program:\n");

    if (scanf("%d", &program) != 1)
    {
        printf("Invalid input.\n");
        return 1;
    }

    if (program < 1 || program > 2)
    {
        printf("Invalid option.\n");
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
