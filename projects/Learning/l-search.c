// Linear search

#include <stdio.h>

int main(void)
{
    int numbers[] = {10 , 20 , 30 , 100 , 15, 300 , 50};

    int n;
    
    printf("Number: ");
    scanf("%i", &n);

    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == n)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}