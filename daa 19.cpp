#include <stdio.h>

struct Item {
    int value;
    int weight;
};

void knapsackGreedy(struct Item items[], int n, int capacity) {
    double totalValue = 0.0;
    double remainingCapacity = (double)capacity;

    for (int i = 0; i < n; i++) {
        if (items[i].weight <= remainingCapacity) {
            totalValue += items[i].value;
            remainingCapacity -= items[i].weight;
        } else {
            totalValue += (double)items[i].value * (remainingCapacity / items[i].weight);
            break;
        }
    }

    printf("Total value in the knapsack: %.2f\n", totalValue);
}

int main() {
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter the value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &items[i].value);
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &items[i].weight);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    knapsackGreedy(items, n, capacity);

    return 0;
}

