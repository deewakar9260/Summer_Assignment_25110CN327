#include <stdio.h>
#include <math.h>
int main() {
    int start, end, i, temp, remainder, digits;
    double sum;
    printf("Enter the starting number: ");
    scanf("%d", &start);
    printf("Enter the ending number: ");
    scanf("%d", &end);
    printf("Armstrong numbers between %d and %d are:\n", start, end);
    for (i = start; i <= end; i++) {
        if (i < 0) {
            continue;
        }
        if (i == 0) {
            printf("0 ");
            continue;
        }

        temp = i;
        sum = 0;
        digits = (int)log10(temp) + 1;
        while (temp > 0) {
            remainder = temp % 10;
            sum += round(pow(remainder, digits));
            temp /= 10;
        }
        if ((int)sum == i) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}
