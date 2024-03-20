#include <stdio.h>

int power(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    return base * power(base, exponent - 1);
}

int order(int num) {
    int count = 0;
    while (num != 0) {
        count++;
        num /= 10;
    }
    return count;
}

int isArmstrong(int num, int originalNum, int n) {
    if (num == 0) {
        return 0;
    }
    return power(num % 10, n) + isArmstrong(num / 10, originalNum, n);
}

int main() {
    int num, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    int n = order(num);

    sum = isArmstrong(num, num, n);

    if (sum == num) {
        printf("%d is an Armstrong number.\n", num);
    } else {
        printf("%d is not an Armstrong number.\n", num);
    }

    return 0;
}
