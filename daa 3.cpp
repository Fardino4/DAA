#include <stdio.h>


int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int factorize(int num, int divisor) {
    if (num == 1)
        return divisor;
    else if (num % divisor == 0)
        return factorize(num / divisor, divisor);
    else
        return factorize(num, divisor + 1);
}

int gcd_recursive_factorization(int num1, int num2) {
    int divisor1 = 2, divisor2 = 2;
    
    int num1_factors = factorize(num1, divisor1);
    int num2_factors = factorize(num2, divisor2);
    
    int result = 1;
    
    for (int i = 2; i <= num1_factors && i <= num2_factors; i++) {
        if (num1_factors % i == 0 && num2_factors % i == 0) {
            result *= i;
            num1_factors /= i;
            num2_factors /= i;
        }
    }
    
    return result;
}

int main() {
    int num1,num2;
    printf("enter the number1:");
    scanf("%d",&num1);
    printf("enter the number2:");
    scanf("%d",&num2);
    
    
    printf("Prime factors of %d: %d\n", num1, factorize(num1, 2));
    printf("Prime factors of %d: %d\n", num2, factorize(num2, 2));
    
    int result = gcd_recursive_factorization(num1, num2);
    
    printf("The GCD of %d and %d is: %d\n", num1, num2, result);
    
    return 0;
}

