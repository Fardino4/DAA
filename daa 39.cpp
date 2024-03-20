#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int costMatrix[MAX][MAX];
int numWorkers, numJobs;
int assignment[MAX];
bool assigned[MAX];
bool visited[MAX];

bool dfs(int worker) {
    visited[worker] = true;

    for (int job = 0; job < numJobs; job++) {
        if (!assigned[job] && costMatrix[worker][job]) {
            assigned[job] = true;

            if (assignment[job] == -1 || dfs(assignment[job])) {
                assignment[job] = worker;
                return true;
            }
        }
    }

    return false;
}

void hungarianAlgorithm() {
    for (int i = 0; i < numJobs; i++)
        assignment[i] = -1;

    int totalAssignments = 0;

    for (int worker = 0; worker < numWorkers; worker++) {
        for (int i = 0; i < numJobs; i++)
            visited[i] = false;

        if (dfs(worker))
            totalAssignments++;
    }

    printf("Optimal Assignment:\n");
    for (int i = 0; i < numJobs; i++)
        printf("Worker %d -> Job %d\n", assignment[i], i);
}

int main() {
    printf("Enter the number of workers: ");
    scanf("%d", &numWorkers);

    printf("Enter the number of jobs: ");
    scanf("%d", &numJobs);

    printf("Enter the cost matrix:\n");
    for (int i = 0; i < numWorkers; i++)
        for (int j = 0; j < numJobs; j++)
            scanf("%d", &costMatrix[i][j]);

    if (numWorkers > MAX || numJobs > MAX) {
        printf("Exceeded maximum limit.\n");
        return 1;
    }

    hungarianAlgorithm();

    return 0;
}
