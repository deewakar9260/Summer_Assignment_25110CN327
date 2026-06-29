#include <stdio.h>
#include <string.h>
#include <ctype.h>

void find_longest_word(const char *str, char *longest) {
    int max_len = 0;
    int curr_len = 0;
    int start_idx = 0;
    int max_start_idx = 0;
    int i = 0;

    while (1) {
        if (isalpha((unsigned char)str[i])) {
            if (curr_len == 0) {
                start_idx = i;
            }
            curr_len++;
        } else {
            if (curr_len > max_len) {
                max_len = curr_len;
                max_start_idx = start_idx;
            }
            curr_len = 0;
            if (str[i] == '\0') {
                break;
            }
        }
        i++;
    }

    if (max_len > 0) {
        strncpy(longest, &str[max_start_idx], max_len);
        longest[max_len] = '\0';
    } else {
        longest[0] = '\0';
    }
}

int main() {
    char sentence[256];
    char longest_word[256];

    printf("Enter a sentence: ");
    if (fgets(sentence, sizeof(sentence), stdin) != NULL) {
        sentence[strcspn(sentence, "\n")] = '\0';

        find_longest_word(sentence, longest_word);

        if (strlen(longest_word) > 0) {
            printf("The longest word is: %s\n", longest_word);
        } else {
            printf("No valid words found.\n");
        }
    }

    return 0;
}
