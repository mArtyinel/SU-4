#include <stdio.h>

#define MAX_VALUES 200000

static int values[MAX_VALUES + 5];
static int tempValues[MAX_VALUES + 5];

void addValue(int x, int *size)
{
    if (*size >= MAX_VALUES)
    {
        printf("Collection is full.\n");
        return;
    }

    values[*size] = x;
    (*size)++;
    printf("Added %d\n", x);
}

void deleteValue(int x, int *size)
{
    int newSize = 0;

    for (int i = 0; i < *size; i++)
    {
        if (values[i] != x)
        {
            values[newSize] = values[i];
            newSize++;
        }
    }

    *size = newSize;
    printf("Deleted all %d\n", x);
}

int kthSmallest(int k, int size)
{
    for (int i = 0; i < size; i++)
    {
        tempValues[i] = values[i];
    }

    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (tempValues[j] < tempValues[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            int swap = tempValues[i];
            tempValues[i] = tempValues[minIndex];
            tempValues[minIndex] = swap;
        }
    }

    return tempValues[k - 1];
}

void printMenu()
{
    printf("Commands:\n");
    printf("1 x -> add(x)\n");
    printf("2 x -> delete(x) (delete all x)\n");
    printf("3 x -> print x-th smallest number\n\n");
}

void processCommand(int type, int x, int *size)
{
    if (type == 1)
    {
        addValue(x, size);
    }
    else if (type == 2)
    {
        deleteValue(x, size);
    }
    else if (type == 3)
    {
        if (x < 1 || x > *size)
        {
            printf("Invalid query\n");
        }
        else
        {
            printf("%d\n", kthSmallest(x, *size));
        }
    }
    else
    {
        printf("Invalid command type\n");
    }
}

int main()
{
    int q;
    printMenu();
    printf("How many commands will you enter? ");
    scanf("%d", &q);

    if (q < 1 || q > MAX_VALUES)
    {
        printf("Invalid number of commands.\n");
        return 1;
    }

    int size = 0;
    printf("Enter commands (type value):\n");

    for (int i = 0; i < q; i++)
    {
        int type, x;
        scanf("%d %d", &type, &x);
        processCommand(type, x, &size);
    }

    return 0;
}
