#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num, int i) {
    if (i == 1) {
        return true;
    } else {
        if (num % i == 0) {
            return false;
        } else {
            return isPrime(num, i - 1);
        }
    }
}

int main() {
    int num;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if (num < 2) {
        printf("%d is not a prime number.\n", num);
    } else {
        if (isPrime(num, num / 2)) {
            printf("%d is a prime number.\n", num);
        } else {
            printf("%d is not a prime number.\n", num);
        }
    }

    return 0;
}
