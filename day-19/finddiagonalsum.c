#include <stdio.h>

int main() {
    int n, sum = 0;

    printf("Enter order of matrix: ");
    scanf("%d", &n);

    int a[n][n];

    printf("Enter matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        sum += a[i][i];
    }

    printf("Sum of diagonal elements = %d\n", sum);

    return 0;
}
