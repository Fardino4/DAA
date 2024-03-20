#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int graph[MAX][MAX];
int path[MAX];
int numVertices;

void printSolution() {
    printf("Hamiltonian Circuit: ");
    for (int i = 0; i < numVertices; i++)
        printf("%d -> ", path[i]);
    printf("%d\n", path[0]);
}

bool isSafe(int v, int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool hamiltonianUtil(int pos) {
    if (pos == numVertices) {
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for (int v = 1; v < numVertices; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v;

            if (hamiltonianUtil(pos + 1))
                return true;

            path[pos] = -1;
        }
    }

    return false;
}

void findHamiltonianCircuit() {
    for (int i = 0; i < numVertices; i++)
        path[i] = -1;

    path[0] = 0;

    if (hamiltonianUtil(1) == false) {
        printf("No Hamiltonian Circuit exists.\n");
        return;
    }

    printSolution();
}

int main() {
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < numVertices; i++)
        for (int j = 0; j < numVertices; j++)
            scanf("%d", &graph[i][j]);

    findHamiltonianCircuit();

    return 0;
}
