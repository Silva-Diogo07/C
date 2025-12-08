#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// PROTÓTIPOS (necessários porque as funções se chamam entre elas)
int askNumber(int trys, int guess, int secret_number);
int checkTrys(int trys, int guess, int secret_number);
int checkNumber(int guess, int secret_number, int trys);

int gerar_secretNumber(int max_number)
{
    srand(time(NULL));
    int secret_number = rand() % (max_number + 1);
    return secret_number;
}

int checkNumber(int guess, int secret_number, int trys)
{
    if (guess > secret_number)
    {
        printf("Mais baixo\n");
        trys--;
        return askNumber(trys, guess, secret_number);
    }
    else if (guess < secret_number)
    {
        printf("Mais alto\n");
        trys--;
        return askNumber(trys, guess, secret_number);
    }

    printf("Acertaste!\n");
    return 0;
}

int checkTrys(int trys, int guess , int secret_number)
{
    if (trys > 1)
    {
        return checkNumber(guess, secret_number, trys);
    }

    printf("Ficaste sem tentativas!\n");
    return 0;
}

int askNumber(int trys , int guess , int secret_number)
{
    guess = get_int("Qual é o teu palpite? ");
    return checkTrys(trys, guess, secret_number);
}

int main(void)
{
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

    askNumber(trys, 0, secret);

    return 0;
}
