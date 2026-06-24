#include <stdio.h>
#include <string.h>

void reverseString(char str[]) {
    int start = 0;
    int end = strlen(str) - 1;
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char str[] = "Hello, World!";
    
    printf("Original: %s\n", str);
    reverseString(str);
    printf("Reversed: %s\n", str);
    
    return 0;
}
