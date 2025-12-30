#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void numero_secreto(int *secret)
{
    int max;

    printf("Qual será o número máximo? ");
    scanf("%d", &max);

    // Inicializa a seed do gerador de números aleatórios
    // time(NULL) garante que o número muda a cada execução
    srand(time(NULL));

    // Gera um número aleatório entre 1 e max
    *secret = (rand() % max) + 1;
}

// Pede ao utilizador o número de tentativas disponíveis
void pedir_tentativas(int *tentativas)
{
    printf("Quantas tentativas queres? ");
    scanf("%d", tentativas);
}

// Pede um palpite ao utilizador
void pedir_palpite(int *palpite)
{
    printf("Qual é o teu palpite? ");
    scanf("%d", palpite);
}

// Verifica se o palpite está correto
// Retorna true se acertar, false caso contrário
bool verificar_palpite(int *palpite, int *secret, int *tentativas)
{
    // Caso o palpite seja maior que o número secreto
    if (*palpite > *secret)
    {
        printf("Mais Baixo\n");
        (*tentativas)--; // Reduz o número de tentativas
        return false;
    }
    // Caso o palpite seja menor que o número secreto
    else if (*palpite < *secret)
    {
        printf("Mais Alto\n");
        (*tentativas)--; // Reduz o número de tentativas
        return false;
    }
    // Caso o palpite esteja correto
    else
    {
        printf("Acertaste\n");
        return true; // Termina o jogo com sucesso
    }
}

void play(int tentativas)
{
    int palpite;
    int secret;

    numero_secreto(&secret);
    // Loop principal do jogo:
    // Continua enquanto o jogador não acertar
    // e ainda houver tentativas disponíveis
    do
    {
        pedir_palpite(&palpite);
    }
    while (!verificar_palpite(&palpite, &secret, &tentativas) && tentativas > 0);
    if (tentativas == 0)
    {
        printf("Acabou o jogo!\n");
    }

}

void playAgain()
{
    int tentativas;

    pedir_tentativas(&tentativas);
    play(tentativas);
}

int main(void)
{
    int tentativas;
    char ask_play[10];

    // Pergunta quantas tentativas o jogador terá
    pedir_tentativas(&tentativas);
    play(tentativas);

    printf("Queres jogar outra vez? ");
    scanf("%9s" , ask_play);

    if (strcmp(ask_play , "sim") == 0)
    {
        playAgain();
    }
}