#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n; 
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2); 
    }
}

 
int main() {
	int i,n;
	printf("enter the no of terms:");
	scanf("%d",&n);
	printf("fibonacci serires:");
    for (int i = 1; i <= n; i++) {
        printf("%d ", fibonacci(i));
    }
    return 0;
}


