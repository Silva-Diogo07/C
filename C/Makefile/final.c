#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


void numero_secreto(int *secret)
{
    int max;

    printf("Qual será o número máximo? ");
    scanf("%d" , &max);

    // Muda a seed para o números não se repetirem ao iniciar o programa não ser sempre o mesmo
    srand(time(NULL));
    // Picks a randomized number
    *secret = (rand() % max) + 1;
}

void pedir_tentativas(int *tentativas)
{
    printf("Quantas tentativas queres? ");
    scanf("%d" , tentativas);
}

void pedir_palpite(int *palpite)
{
    printf("Qual é o teu palpite? ");
    scanf("%d" , palpite);
}

bool verificar_palpite(int *palpite , int *secret , int *tentativas)
{
    if (*palpite > *secret)
    {
        printf("Mais Baixo\n");
        (*tentativas)--;
        return false;
    }
    else if (*palpite < *secret)
    {
        printf("Mais Alto\n");
        (*tentativas)--;
        return false;
    }
    else
    {
        printf("Acertaste\n");
        return true;
    }
}

int main(void)
{
    int tentativas;
    int palpite;
    int secret;
    numero_secreto(&secret);
    pedir_tentativas(&tentativas);

    do
    {
        pedir_palpite(&palpite);
    }
    while (!verificar_palpite(&palpite , &secret , &tentativas) && tentativas > 0);

    printf("Perdeste\n");
    printf("\n");
    printf("Debug\n");
    printf("Número Secreto : %d\n" , secret);
}


// TODO : playAgain

