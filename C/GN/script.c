#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// PROTÓTIPOS
int askNumber(int trys, int secret_number, int max_number);
int checkTrys(int trys, int guess, int secret_number, int max_number);
int checkNumber(int guess, int secret_number, int trys, int max_number);
int playAgain(void);
int gerar_secretNumber(int max_number);

int playAgain(void)
{
    int trys = get_int("Quantas tentativas queres? ");
    int max_number = get_int("Qual será o número máximo? ");

    int secret_number = gerar_secretNumber(max_number);

    printf("DEBUG → novo número secreto: %i\n", secret_number);

    askNumber(trys, secret_number, max_number);

    return 0;
}

int gerar_secretNumber(int max_number)
{
    return rand() % (max_number + 1);
}

int checkNumber(int guess, int secret_number, int trys, int max_number)
{
    if (guess > secret_number)
    {
        printf("Mais baixo\n");
        trys--;
        return askNumber(trys, secret_number, max_number);
    }
    else if (guess < secret_number)
    {
        printf("Mais alto\n");
        trys--;
        return askNumber(trys, secret_number, max_number);
    }

    printf("Acertaste!\n");

    string again = get_string("Queres jogar outra vez? (sim/não) ");
    if (strcmp(again, "sim") == 0)
    {
        return playAgain();
    }

    printf("Obrigado por jogar!\n");
    return 0;
}

int checkTrys(int trys, int guess, int secret_number, int max_number)
{
    if (trys > 1)
    {
        return checkNumber(guess, secret_number, trys, max_number);
    }
    else
    {
        // Última tentativa
        if (guess > secret_number)
        {
            printf("Mais baixo\n");
        }
        else if (guess < secret_number)
        {
            printf("Mais alto\n");
        }

        printf("Perdeste! O número era %d.\n", secret_number);

        string again = get_string("Queres jogar outra vez? (sim/não) ");
        if (strcmp(again, "sim") == 0)
        {
            return playAgain();
        }

        printf("Obrigado por jogar!\n");
        return 0;
    }
}

int askNumber(int trys, int secret_number, int max_number)
{
    int guess = get_int("Qual é o teu palpite? ");
    return checkTrys(trys, guess, secret_number, max_number);
}

int main(void)
{
    srand(time(NULL));

    string nome = get_string("Qual é o teu nome? ");
    printf("Olá, %s!\n", nome);

    string p1 = get_string("Queres jogar um jogo? (sim/não) ");

    if (strcmp(p1, "sim") != 0)
    {
        printf("Então fica para a próxima!\n");
        return 0;
    }

    int trys = get_int("Quantas tentativas queres? ");
    int max_number = get_int("Qual será o número máximo? ");

    int secret = gerar_secretNumber(max_number);

    printf("DEBUG → número secreto: %i\n", secret);

    askNumber(trys, secret, max_number);

    return 0;
}
