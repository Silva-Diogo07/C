#include <stdio.h>
#include <string.h>

int main(void)
{
    char *strings[] = {"orange", "banana", "apple", "peach", "strawberry"};
    char s[50];

    printf("String: ");
    scanf("%49s", s);

    for (int i = 0; i < 5; i++)
    {
        if (strcmp(strings[i], s) == 0)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}