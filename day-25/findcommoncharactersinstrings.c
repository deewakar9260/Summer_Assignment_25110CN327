#include <stdio.h>
#include <string.h>

void findCommonChars(const char *str1, const char *str2) {
    int freq1[256] = {0};
    int freq2[256] = {0};
    
    for (int i = 0; str1[i] != '\0'; i++) {
        freq1[(unsigned char)str1[i]] = 1;
    }
    
    for (int i = 0; str2[i] != '\0'; i++) {
        freq2[(unsigned char)str2[i]] = 1;
    }
    
    printf("Common characters: ");
    int found = 0;
    for (int i = 0; i < 256; i++) {
        if (freq1[i] && freq2[i]) {
            if (i == ' ') {
                printf("[Space] ");
            } else if (i == '\n') {
                continue;
            } else {
                printf("%c ", i);
            }
            found = 1;
        }
    }
    
    if (!found) {
        printf("None");
    }
    printf("\n");
}

int main() {
    char str1[256];
    char str2[256];
    
    printf("Enter first string: ");
    if (fgets(str1, sizeof(str1), stdin) == NULL) return 1;
    
    printf("Enter second string: ");
    if (fgets(str2, sizeof(str2), stdin) == NULL) return 1;
    
    findCommonChars(str1, str2);
    
    return 0;
}
