
#include <stdio.h>
#include <stdlib.h>

float sum(float freq[], int i, int j) {
    float s = 0;
    for (int k = i; k <= j; k++)
        s += freq[k];
    return s;
}


float optimalBST(float keys[], float freq[], int n) {
    
    float cost[n][n];

    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cost[i][j] = 0;

    
    for (int i = 0; i < n; i++)
        cost[i][i] = freq[i];

    
    for (int L = 2; L <= n; L++) {
        for (int i = 0; i <= n - L + 1; i++) {
            int j = i + L - 1;
            cost[i][j] = __FLT_MAX__;

            // Try making all keys in keys[i..j] as root
            for (int r = i; r <= j; r++) {
                float c = ((r > i) ? cost[i][r - 1] : 0) +
                          ((r < j) ? cost[r + 1][j] : 0) +
                          sum(freq, i, j);
                if (c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }

    
    return cost[0][n - 1];
}

int main() {
    int n;
    printf("Enter the number of keys: ");
    scanf("%d", &n);

    float *keys = (float *)malloc(n * sizeof(float));
    float *freq = (float *)malloc(n * sizeof(float));

    printf("Enter the keys:\n");
    for (int i = 0; i < n; i++)
        scanf("%f", &keys[i]);

    printf("Enter the frequencies:\n");
    for (int i = 0; i < n; i++)
        scanf("%f", &freq[i]);

    printf("Cost of Optimal BST is %f\n", optimalBST(keys, freq, n));

    free(keys);
    free(freq);
    return 0;
}

