#include <stdio.h>
#include <limits.h>

void readMatrix(int n, int m, int arr[n][m])
{
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
}

void printMatrix(int n, int m, int arr[n][m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void findRowsWithMinAndMax(int n, int m, int arr[n][m], int *minRow, int *maxRow)
{
    int minElement = INT_MAX;
    int maxElement = INT_MIN;

    *minRow = 0;
    *maxRow = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] > maxElement)
            {
                maxElement = arr[i][j];
                *maxRow = i;
            }

            if (arr[i][j] < minElement)
            {
                minElement = arr[i][j];
                *minRow = i;
            }
        }
    }
}

void swapRows(int m, int arr[][m], int rowA, int rowB)
{
    for (int j = 0; j < m; j++)
    {
        int temp = arr[rowA][j];
        arr[rowA][j] = arr[rowB][j];
        arr[rowB][j] = temp;
    }
}


int main()
{
    int n, m;
    printf("Enter N: ");
    scanf("%d", &n);
    printf("Enter M: ");
    scanf("%d", &m);

    int arr[n][m];
    readMatrix(n, m, arr);

    printf("Array before swap:\n");
    printMatrix(n, m, arr);

    int maxRow = 0;
    int minRow = 0;
    findRowsWithMinAndMax(n, m, arr, &minRow, &maxRow);
    swapRows(m, arr, maxRow, minRow);

    printf("Array after swap:\n");
    printMatrix(n, m, arr);

    return 0;
}
