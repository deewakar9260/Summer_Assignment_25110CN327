#include <stdio.h>

int sum(int num1, int num2) {
    return num1 + num2;
}

int main() {
    int a, b, result;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    result = sum(a, b);

    printf("The sum is: %d\n", result);

    return 0;
}
