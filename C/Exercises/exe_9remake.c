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

// Binary search única que funciona para ambas as ordens
int binarySearch(int arr[], int n, int target, int ascending)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }

        if (ascending)
        {
            if (arr[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        else
        {
            if (arr[mid] > target)
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int main(void)
{
    int n;
    int arr[100];
    int target;

    do
    {
        printf("Numbers of elements: ");
        scanf("%d", &n);
    }
    while (n < 2 || n > 100);

    saveNumber(n, arr);

    char option[15];
    printf("Enter how to order numbers ( < | > ): ");
    scanf(" %14s", option);

    int ascending; // 1 = crescente, 0 = decrescente

    if (strcmp(option, ">") == 0)
    {
        high_to_low(n, arr);
        ascending = 0;
    }
    else if (strcmp(option, "<") == 0)
    {
        low_to_high(n, arr);
        ascending = 1;
    }
    else
    {
        printf("Invalid option\n");
        return 1;
    }

    printArr(n, arr);

    printf("Number to be found: ");
    scanf("%d", &target);

    int result = binarySearch(arr, n, target, ascending);

    if (result != -1)
    {
        printf("Number found at index[%d]\n", result);
    }
    else
    {
        printf("Number not found\n");
    }

    return 0;
}
