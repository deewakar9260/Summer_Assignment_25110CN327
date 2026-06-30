#include <stdio.h>
#include <string.h>

void sort_words(char *str) {
    char words[100][50];
    int count = 0;
    
    char *token = strtok(str, " \t\n,.");
    while (token != NULL) {
        strcpy(words[count], token);
        count++;
        token = strtok(NULL, " \t\n,.");
    }
    
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strlen(words[j]) > strlen(words[j + 1])) {
                char temp[50];
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
            }
        }
    }
    
    printf("Sorted words:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", words[i]);
    }
}

int main(void) {
    char str[1000];
    
    printf("Enter a sentence: ");
    if (fgets(str, sizeof(str), stdin) != NULL) {
        sort_words(str);
    }
    
    return 0;
}
