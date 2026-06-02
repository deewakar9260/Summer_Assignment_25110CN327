#include <stdio.h>
int main() {
    int num, originalNum, remainder;
    int reversedNum = 0;
    printf("Enter an integer: ");
    scanf("%d",&num);
    originalNum = num;
    while (num != 0) {
        remainder = num % 10;
        reversedNum = (reversedNum * 10) + remainder;
        num /= 10;
    }
    if (originalNum == reversedNum) {
        printf("%d is a palindrome.\n", originalNum);
    } else {
        printf("%d is not a palindrome.\n", originalNum);
    }
    return 0;
}
