#include <stdio.h>
#include <string.h>

void saveNumber(int n, int arr[])
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void low_to_high(int n, int arr[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void high_to_low(int n, int arr[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArr(int n, int arr[])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    int n;
    int arr[100];

    printf("Number of elements: ");
    scanf("%d", &n);

    char option[100];
    printf("Enter how to order numbers ( l-h | h-l ) ");
    scanf("%99s", option);

    if (strcmp(option, "h-l") == 0)
    {
        printf("Banana\n");
        return 0;
    }
    printf("Kiwi\n");

    return 0;

    // saveNumber(n, arr);
    // high_to_low(n, arr);
    // printArr(n, arr);
    
}
