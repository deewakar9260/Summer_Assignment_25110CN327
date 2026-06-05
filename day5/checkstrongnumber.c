#include <stdio.h>
long long getFactorial(int digit) {
    long long fact = 1;
    for (int i = 1; i <= digit; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int num, originalNum, rem;
    long long sum = 0;
    printf("Enter an integer to check: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    originalNum = num;
    if (num < 0) {
        printf("%d is not a Strong Number.\n", originalNum);
        return 0;
    }
    while (num > 0) {
        rem = num % 10;           
        sum += getFactorial(rem);  
        num = num / 10;            
    }
    if (sum == originalNum) {
        printf("%d is a Strong Number.\n", originalNum);
    } else {
        printf("%d is not a Strong Number.\n", originalNum);
    }

    return 0;
}
