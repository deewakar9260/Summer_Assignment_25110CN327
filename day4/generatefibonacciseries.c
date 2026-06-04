#include <stdio.h>

int main() {
    int n;
    unsigned long long t1 = 0, t2 = 1, nextTerm;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Please enter a positive integer greater than 0.\n");
        return 0;
    }

    printf("Fibonacci Series: ");

    for (int i = 1; i <= n; ++i) {
        printf("%llu", t1);
        
        if (i < n) {
            printf(", ");
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }

    printf("\n");
    return 0;
}
