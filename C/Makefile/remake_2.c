#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int ask_tries()
{
    // ask the user to define how many trys
    int tries = get_int("Quantas tentativas queres?\n");
    return tries;
}

int ask_max()
{
    // ask the user to define the max_number
    int max_number = get_int("Qual o número máximo?\n");
    return max_number;
}

int ask_guess()
{
    // asks the user's guess
    int guess = get_int("Qual é o teu palpite? ");
    return guess;
}

// TODO : Função asks_management
// TODO : While tentativas > 0 
// play()
