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

int neighborhoodSum(int n, int m, int arr[n][m], int row, int col)
{
    int currSum = 0;

    for (int r = row - 1; r <= row + 1; r++)
    {
        for (int c = col - 1; c <= col + 1; c++)
        {
            if (r >= 0 && r < n && c >= 0 && c < m)
            {
                currSum += arr[r][c];
            }
        }
    }

    return currSum;
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

    int maxSum = INT_MIN;
    int maxRow = 0;
    int maxCol = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int currSum = neighborhoodSum(n, m, arr, i, j);

            if (currSum > maxSum)
            {
                maxSum = currSum;
                maxRow = i;
                maxCol = j;
            }
        }
    }

    printf("The array is:\n");
    printMatrix(n, m, arr);

    printf("The num with biggest sum is: %d\n", arr[maxRow][maxCol]);
    printf("The sum is: %d\n", maxSum);
    return 0;
}
