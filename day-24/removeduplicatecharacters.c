#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void removeDuplicates(char* str) {
    bool seen[256] = { false };
    int writeIndex = 0;
    
    for (int readIndex = 0; str[readIndex] != '\0'; readIndex++) {
        unsigned char ch = str[readIndex];
        if (!seen[ch]) {
            seen[ch] = true;
            str[writeIndex++] = str[readIndex];
        }
    }
    str[writeIndex] = '\0';
}

int main() {
    char str[] = "programming sample";
    
    printf("Original: %s\n", str);
    removeDuplicates(str);
    printf("Modified: %s\n", str);
    
    return 0;
}
