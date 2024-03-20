#include <stdio.h>

int isPrime(int num, int i) {
    if (i == 1) {
        return 1;
    } else {
        if (num % i == 0) {
            return 0;
        } else {
            return isPrime(num, i - 1);
        }
    }
}

void generatePrimes(int n, int i) {
    if (n < 2)
        return;

    if (isPrime(i, i / 2)) {
        printf("%d ", i);
    }

    generatePrimes(n - 1, i + 1);
}

int main() {
    int limit;

    printf("Enter the limit to generate prime numbers up to: ");
    scanf("%d", &limit);

    printf("Prime numbers up to %d are: ", limit);
    generatePrimes(limit, 2);

    return 0;
}

