#include <stdio.h>
int main() {
    int n, i;
    printf("Enter an integer: ");
    scanf("%d", &n);

    printf("\nMultiplication Table of %d:\n", n);
    printf("---------------------------\n");
    for (i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", n, i, n * i);
    }
    return 0;
}
