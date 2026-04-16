#include <stdio.h>

#define MAX_N 100000
#define MAX_M 1000000

static int head[MAX_N + 5];
static int degreeArr[MAX_N + 5];
static int to[2 * MAX_M + 5];
static int nextEdge[2 * MAX_M + 5];

void initGraph(int n)
{
    for (int i = 1; i <= n; i++)
    {
        head[i] = -1;
        degreeArr[i] = 0;
    }
}

void addFriendship(int a, int b, int *edgeIndex)
{
    to[*edgeIndex] = b;
    nextEdge[*edgeIndex] = head[a];
    head[a] = *edgeIndex;
    (*edgeIndex)++;

    to[*edgeIndex] = a;
    nextEdge[*edgeIndex] = head[b];
    head[b] = *edgeIndex;
    (*edgeIndex)++;

    degreeArr[a]++;
    degreeArr[b]++;
}

void printFriends(int person)
{
    if (degreeArr[person] == 0)
    {
        printf("No friends.\n");
        return;
    }

    printf("Friends: ");
    for (int i = head[person]; i != -1; i = nextEdge[i])
    {
        printf("%d ", to[i]);
    }
    printf("\n");
}

int main()
{
    int n, m;
    printf("Enter N: ");
    scanf("%d", &n);
    printf("Enter M: ");
    scanf("%d", &m);

    if (n < 1 || n > MAX_N || m < 1 || m > MAX_M)
    {
        printf("Invalid\n");
        return 0;
    }

    initGraph(n);

    printf("Enter %d friendships (a b):\n", m);

    int edgeIndex = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        if (a < 1 || a > n || b < 1 || b > n)
        {
            continue;
        }

        addFriendship(a, b, &edgeIndex);
    }

    int person;
    printf("Enter person number: ");
    scanf("%d", &person);

    if (person < 1 || person > n)
    {
        printf("Invalid person number.\n");
        return 0;
    }

    printf("Person %d has %d friends.\n", person, degreeArr[person]);

    printFriends(person);
    return 0;
}
