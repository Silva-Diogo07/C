#include <stdio.h>

int main(void)
{
    char *words[] = {"Hello", "World!"};
    
    printf("%s\n" , words[0]);
    printf("%s\n" , words[1]);

    printf("%c\n" , words[0][0]);
    printf("%c\n" , words[1][1]);
}
