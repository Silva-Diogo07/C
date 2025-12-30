#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int numero_secreto(int max)
{
    return (rand() % max) + 1;
}

int verificar_palpite(int palpite, int secreto)
{
    if (palpite > secreto)
    {
        printf("Mais baixo\n");
        return 0;
    }
    else if (palpite < secreto)
    {
        printf("Mais alto\n");
        return 0;
    }
    else
    {
        printf("Acertaste!\n");
        return 1;
    }
}

int main(void)
{
    srand(time(NULL));

    int max;
    int tentativas;
    int palpite;

    printf("Digita o número máximo: ");
    scanf("%d", &max);

    while (max <= 0)
    {
        printf("Número inválido. Digita novamente: ");
        scanf("%d", &max);
    }

    int secreto = numero_secreto(max);

    printf("Quantas tentativas queres? ");
    scanf("%d", &tentativas);

    while (tentativas > 0)
    {
        printf("Digita o teu palpite: ");
        scanf("%d", &palpite);

        if (verificar_palpite(palpite, secreto))
        {
            break;
        }

        tentativas--;
        printf("Tentativas restantes: %d\n", tentativas);
    }

    if (tentativas == 0)
    {
        printf("Perdeste! O número era %d\n", secreto);
    }

    return 0;
}
