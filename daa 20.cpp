
#include <stdio.h>
#include <limits.h>

#define V 100

int minKey(int key[], int mstSet[], int n)
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int n, int graph[V][V])
{
    printf("Edge   Weight\n");
    for (int i = 1; i < n; i++)
        printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V], int n)
{
    int parent[V];
    int key[V];
    int mstSet[V];

    for (int i = 0; i < n; i++)
        key[i] = INT_MAX, mstSet[i] = 0;

    parent[0] = -1;
    key[0] = 0;

    for (int count = 0; count < n - 1; count++)
    {
        int u = minKey(key, mstSet, n);

        mstSet[u] = 1;

        for (int v = 0; v < n; v++)
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, n, graph);
}

int main()
{
    int n;
    
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    int graph[V][V];

    printf("Enter the adjacency matrix of the graph:\n");
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(graph, n);

    return 0;
}

