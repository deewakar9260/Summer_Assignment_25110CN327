#include <stdio.h>
int find_gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return find_gcd(b, a % b);
}
int find_lcm(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    return (a * b) / find_gcd(a, b);
}
int main() {
    int num1, num2, lcm;

    printf("Enter two positive integers: ");
    if (scanf("%d %d", &num1, &num2) != 2) {
        printf("Invalid input.\n");
        return 1;
    }
    int absolute_num1 = (num1 < 0) ? -num1 : num1;
    int absolute_num2 = (num2 < 0) ? -num2 : num2;
    lcm = find_lcm(absolute_num1, absolute_num2);
    printf("The LCM of %d and %d is: %d\n", num1, num2, lcm);
    return 0;
}
