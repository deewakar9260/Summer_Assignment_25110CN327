#include <stdio.h>
int main() {
    int num, remainder;
    long long product = 1; 
    printf("Enter any integer: ");
    scanf("%d", &num);
    if (num < 0) {
        num = -num;
    }
    if (num == 0) {
        product = 0;
    } else {
        while (num > 0) {
            remainder = num % 10;       
            product = product * remainder; 
            num = num / 10;             
        }
    }
    printf("Product of the digits = %lld\n", product);
    return 0;
}
