#include <stdio.h>

void printFibonacci(int n) {
    if (n < 1) {
        printf("Invalid number of terms.\n");
        return;
    }
    
    long long first = 0, second = 1, next;
    
    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            next = i;
        } else {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%lld ", next);
    }
    printf("\n");
}

int main() {
    int terms;
    
    printf("Enter the number of terms: ");
    if (scanf("%d", &terms) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    
    printf("Fibonacci Series: ");
    printFibonacci(terms);
    
    return 0;
}
