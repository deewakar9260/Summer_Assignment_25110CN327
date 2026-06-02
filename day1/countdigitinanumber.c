#include <stdio.h>
int main() {
    long long num;
    int count = 0;
    printf("Enter an integer: ");
    scanf("%lld", &num);
    long long original_num = num;
    do {
        count++;
        num /= 10; 
    } while (num != 0);
    printf("The number of digits in %lld is: %d\n", original_num, count);
    return 0;
}
