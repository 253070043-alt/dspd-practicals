#include <stdio.h>
#include <stdlib.h>
#define N 9
int adj[N + 1][N + 1];
int visited[N + 1];
void createGraph()
{
    int i, j;
    for (i = 1; i <= N; i++)
        for (j = 1; j <= N; j++)
            adj[i][j] = 0;
    adj[1][2] = adj[2][1] = 1;
    adj[1][4] = adj[4][1] = 1;
    adj[2][3] = adj[3][2] = 1;
    adj[2][5] = adj[5][2] = 1;
    adj[3][6] = adj[6][3] = 1;
    adj[4][5] = adj[5][4] = 1;
    adj[4][7] = adj[7][4] = 1;
    adj[5][6] = adj[6][5] = 1;
    adj[5][8] = adj[8][5] = 1;
    adj[6][9] = adj[9][6] = 1;
    adj[7][8] = adj[8][7] = 1;
    adj[8][9] = adj[9][8] = 1;
}
void bfs(int start)
{
    int queue[20], front = 0, rear = 0;
    int i, node;
    for (i = 1; i <= N; i++)
        visited[i] = 0;
    printf("BFS order: ");
    visited[start] = 1;
    queue[rear++] = start;
    while (front < rear)
    {
        node = queue[front++];
        printf("%d ", node);
        for (i = 1; i <= N; i++)
        {
            if (adj[node][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}
void dfs(int start)
{
    int stack[20], top = -1;
    int i, node;
    for (i = 1; i <= N; i++)
        visited[i] = 0;
    printf("DFS order: ");
    stack[++top] = start;
    while (top != -1)
    {
        node = stack[top--];
        if (!visited[node])
        {
            visited[node] = 1;
            printf("%d ", node);
            for (i = N; i >= 1; i--)
            {
                if (adj[node][i] == 1 && visited[i] == 0)
                    stack[++top] = i;
            }
        }
    }
    printf("\n");
}
int main()
{
    int ch;
    createGraph();
    while (1)
    {
        printf("\n1. Perform BFS\n2. Perform DFS\n3. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            bfs(1);
            break;
        case 2:
            dfs(1);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
