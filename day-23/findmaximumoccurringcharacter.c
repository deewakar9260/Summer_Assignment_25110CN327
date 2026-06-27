#include <stdio.h>
#include <string.h>

char getMaxOccurringChar(char str[]) {
    int count[256] = {0};
    int length = strlen(str);
    int maxCount = 0;
    char maxChar = ' ';

    for (int i = 0; i < length; i++) {
        count[(unsigned char)str[i]]++;
    }

    for (int i = 0; i < length; i++) {
        if (count[(unsigned char)str[i]] > maxCount) {
            maxCount = count[(unsigned char)str[i]];
            maxChar = str[i];
        }
    }

    return maxChar;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    char maxChar = getMaxOccurringChar(str);

    printf("Maximum occurring character is: '%c'\n", maxChar);

    return 0;
}
