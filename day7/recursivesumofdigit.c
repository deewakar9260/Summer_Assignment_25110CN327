#include <stdio.h>
int sumOfDigits(int num);

int main() {
    int number, result;
    printf("Enter an integer: ");
    scanf("%d", &number);
    if (number < 0) {
        number = -number;
    }
    result = sumOfDigits(number);
    printf("Sum of digits: %d\n", result);

    return 0;
}
int sumOfDigits(int num) {
    // Base case: if number becomes 0, return 0
    if (num == 0) {
        return 0;
    }
    return (num % 10) + sumOfDigits(num / 10);
}
