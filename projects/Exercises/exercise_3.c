// README - Exercise made to practise and how to understand loops

#include <stdio.h>

void forLoop(int x)
{
    int i;

    for (i = 0; i < x; i++)
    {
        printf("%d\n" , i + 1);
    }
}

void whileLoop(int y)
{
    int i = 0;
    while (i < y)
    {
        printf("%d\n" , i + 1);
        i++;
    }
}

void do_whileLoop(int z)
{
    int i = 0;
    if (z <= 0) return;

    do
    {
        printf("%d\n" , i + 1);
        i++;
    }
    while (i < z);
}

int main(void)
{
    int x;
    int y;
    int z;

    printf("Digita x: ");
    scanf("%d", &x );

    printf("\n");
    forLoop(x);
    printf("\n");

    printf("Digita y: ");
    scanf("%d", &y);

    printf("\n");
    whileLoop(y);
    printf("\n");

    printf("Digita z: ");
    scanf("%d", &z);

    printf("\n");
    do_whileLoop(z);
    printf("\n");

    return 0;
}