#include <stdio.h>
#include <string.h>

char findFirstRepeating(char *str) {
    int visited[256] = {0};
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (visited[(unsigned char)str[i]] == 1) {
            return str[i];
        }
        visited[(unsigned char)str[i]] = 1;
    }
    
    return '\0';
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin)) {
        str[strcspn(str, "\n")] = '\0';
    }
    
    char result = findFirstRepeating(str);
    
    if (result != '\0') {
        printf("First repeating character: %c\n", result);
    } else {
        printf("No repeating characters found.\n");
    }
    
    return 0;
}
