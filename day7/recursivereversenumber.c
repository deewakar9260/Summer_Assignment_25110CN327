#include <stdio.h>

int reverseNumber(int num, int rev) {
    if (num == 0) {
        return rev;
    }
    return reverseNumber(num / 10, rev * 10 + num % 10);
}

int main() {
    int number;
    printf("Enter an integer: ");
    if (scanf("%d", &number) == 1) {
        int result = reverseNumber(number, 0);
        printf("Reversed number: %d\n", result);
    }
    return 0;
}
