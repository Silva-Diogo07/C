#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int askTrys(void);
int ask_maxNumber(void);
int gerar_secretNumber(int max_number);
void checkTrys(int trys , int secretNumber);
int ask_Number(int secretNumber, int trys);
int playAgain(int secretNumber , int trys);

int playAgain(int secretNumber , int trys)
{
    string ask_playAgain = get_string("Queres jogar outra vez? (sim/não) ");

    if (strcmp(ask_playAgain, "sim") == 0)
    {
        int max_number = ask_maxNumber();
        trys = askTrys();
        secretNumber = gerar_secretNumber(max_number);
        checkTrys(trys, secretNumber);
    }
    else
    {
        printf("Até à próxima!\n");
    }

    return 0;
}

int ask_maxNumber(void)
{
    return get_int("Qual o número máximo que queres?\n");
}

int gerar_secretNumber(int max_number)
{
    return rand() % (max_number + 1);
}

int askTrys(void)
{
    return get_int("Quantas tentativas queres?\n");
}

int checkNumber(int guess, int secretNumber , int trys)
{
    if (guess > secretNumber)
    {
        printf("Mais Baixo\n");
        return -1;
    }
    else if (guess < secretNumber)
    {
        printf("Mais Alto\n");
        return -1;
    }
    else
    {
        printf("Acertaste!\n");
        playAgain(secretNumber , trys);
        return 0;
    }
}

int ask_Number(int secretNumber, int trys)
{
    int guess = get_int("Qual é o teu palpite? ");
    return checkNumber(guess, secretNumber , trys);
}

void checkTrys(int trys, int secretNumber)
{
    while (trys > 0)
    {
        int result = ask_Number(secretNumber, trys);
        if (result == 0)
        {
            return;
        }
        trys--;
    }
    
        printf("Acabaram as tentativas\n");
        playAgain(secretNumber, trys);
}

int main(void)
{
    srand(time(NULL));

    int trys = askTrys();
    int max_number = ask_maxNumber();
    int secretNumber = gerar_secretNumber(max_number);

    printf("Número secreto: %i\n", secretNumber); // Debug

    checkTrys(trys, secretNumber);
}
