#include <stdio.h>

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

int isValid(int n, int m, int arr[n][m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            if (arr[i][j] >= arr[i][j + 1])
            {
                return 0;
            }
        }
    }

    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i][j] >= arr[i + 1][j])
            {
                return 0;
            }
        }
    }

    return 1;
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

    if (isValid(n, m, arr))
    {
        printf("Valid\n");
    }
    else
    {
        printf("Invalid\n");
    }
    return 0;
}
