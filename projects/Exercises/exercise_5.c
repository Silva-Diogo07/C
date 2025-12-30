// README - Exercise made to practise while loop and input validation

#include <stdio.h>

int ask_number(void)
{
    int num;
    printf("Escolhe um numero de 1-10: ");
    scanf("%i", &num);
    return num;
}

int verificar_num(int num)
{
    while (num < 1 || num > 10)
    {
        printf("Numero inválido. Digite um numero de 1-10: ");
        scanf("%i", &num);
    }
    return num;
}

int main(void)
{
    int num;

    num = ask_number();
    num = verificar_num(num);

    printf("Concluido! Numero escolhido: %i\n", num);
    return 0;
}
