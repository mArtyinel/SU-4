#include <stdio.h>
#include <limits.h>

int main()
{
    int n, m;
    printf("Enter N: ");
    scanf("%d", &n);
    printf("Enter M: ");
    scanf("%d", &m);
    int arr[n][m];

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int max_sum = INT_MIN;

    int max_row = 0, max_col = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int curr_sum = 0;

            for (int r = i - 1; r <= i + 1; r++)
            {
                for (int c = j - 1; c <= j + 1; c++)
                {

                    if (r >= 0 && r < n && c >= 0 && c < m)
                    {
                        curr_sum += arr[r][c];
                    }
                }
            }

            if (curr_sum > max_sum)
            {
                max_sum = curr_sum;
                max_row = i;
                max_col = j;
            }
        }
    }

    printf("The array is:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    printf("biggest 3x3 matrix is:\n");
    for (int r = max_row - 1; r <= max_row + 1; r++)
    {
        for (int c = max_col - 1; c <= max_col + 1; c++)
        {
            if (r >= 0 && r < n && c >= 0 && c < m)
            {
                printf("%d ", arr[r][c]);
            }
            else
            {
                printf("X ");
            }
        }
        printf("\n");
    }
}