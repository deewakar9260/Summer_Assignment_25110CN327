#include <stdio.h>
unsigned long long factorial(unsigned int n);

int main() {
    unsigned int num;
    
    printf("Enter a positive integer: ");
    if (scanf("%u", &num) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    printf("Factorial of %u = %llu\n", num, factorial(num));
    
    return 0;
}
unsigned long long factorial(unsigned int n) {
    if (n <= 1) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}
