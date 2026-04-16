#include <stdio.h>

#define MAX_SIZE 1000

int isPrime(int num)
{
    if (num <= 1)
    {
        return 0;
    }

    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

int main(void)
{
    int n;
    int arr[MAX_SIZE];
    int primeArr[MAX_SIZE];
    int nonPrimeCount = 0;
    int primeCount = 0;

    printf("Enter the number of elements (max %d): ", MAX_SIZE);
    if (scanf("%d", &n) != 1)
    {
        printf("Invalid input.\n");
        return 1;
    }

    if (n < 1 || n > MAX_SIZE)
    {
        printf("Invalid number of elements.\n");
        return 1;
    }

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            printf("Invalid input.\n");
            return 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (isPrime(arr[i]))
        {
            primeArr[primeCount++] = arr[i];
        }
        else
        {
            arr[nonPrimeCount++] = arr[i];
        }
    }

    printf("Array without prime numbers:\n");
    for (int i = 0; i < nonPrimeCount; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Prime numbers array:\n");
    for (int i = 0; i < primeCount; i++)
    {
        printf("%d ", primeArr[i]);
    }
    printf("\n");

    return 0;
}
