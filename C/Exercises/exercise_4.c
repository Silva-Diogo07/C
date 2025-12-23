// README - Exercise to practise input validation

#include <stdio.h>

int calcular(int x, int y, char o)
{
    switch (o)
    {
        case '+': return x + y;
        case '-': return x - y;
        case '*': return x * y;
        case '/':
            if (y == 0)
            {
                printf("Erro: divisão por zero\n");
                return 0;
            }
            return x / y;
        default:
            printf("Operador inválido\n");
            return 0;
    }
}

int main(void)
{
    int x, y;
    char o;

    printf("Escolhe x: ");
    scanf("%d", &x);

    printf("Escolhe y: ");
    scanf("%d", &y);

    printf("Operator (+ - * /): ");
    scanf(" %c", &o);

    int resultado = calcular(x, y, o);

    printf("O resultado é: %d\n", resultado);

    return 0;
}
