#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 10;
    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    while (1)
    {
        int number, position;
        printf("Enter a number and its position (0 to stop): ");
        scanf("%d", &number);

        if (number == 0)
        {
            break;
        }

        scanf("%d", &position);

        if (position < 0 || position > n)
        {
            printf("Invalid position. Try again.\n");
            continue;
        }

        arr = (int *)realloc(arr, (n + 1) * sizeof(int));

        if (arr == NULL)
        {
            printf("Memory reallocation failed.\n");
            return 1;
        }

        for (int i = n; i > position; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[position] = number;
        n++;
    }

    printf("Final array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}