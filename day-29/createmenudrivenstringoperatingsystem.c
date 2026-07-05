#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void upper_string(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}

void lower_string(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int count_vowels(const char *str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower((unsigned char)str[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }
    return count;
}

int main() {
    char str1[200], str2[100];
    int choice;

    printf("Enter a string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';

    do {
        printf("\n--- String OS Menu ---\n");
        printf("1. Display Current String\n");
        printf("2. Find Length\n");
        printf("3. Reverse String\n");
        printf("4. Convert to Uppercase\n");
        printf("5. Convert to Lowercase\n");
        printf("6. Count Vowels\n");
        printf("7. Concatenate Another String\n");
        printf("8. Compare with Another String\n");
        printf("9. Enter a New Base String\n");
        printf("10. Exit\n");
        printf("Enter your choice (1-10): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }
        while (getchar() != '\n'); 

        switch (choice) {
            case 1:
                printf("Current String: \"%s\"\n", str1);
                break;
            case 2:
                printf("Length: %lu\n", strlen(str1));
                break;
            case 3:
                reverse_string(str1);
                printf("Reversed String: \"%s\"\n", str1);
                break;
            case 4:
                upper_string(str1);
                printf("Uppercase String: \"%s\"\n", str1);
                break;
            case 5:
                lower_string(str1);
                printf("Lowercase String: \"%s\"\n", str1);
                break;
            case 6:
                printf("Number of vowels: %d\n", count_vowels(str1));
                break;
            case 7:
                printf("Enter string to append: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0';
                if (strlen(str1) + strlen(str2) < sizeof(str1)) {
                    strcat(str1, str2);
                    printf("Concatenated String: \"%s\"\n", str1);
                } else {
                    printf("Error: Buffer overflow prevented.\n");
                }
                break;
            case 8:
                printf("Enter string to compare: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0';
                int cmp = strcmp(str1, str2);
                if (cmp == 0) {
                    printf("Strings are identical.\n");
                } else if (cmp < 0) {
                    printf("Current string comes before the entered string alphabetically.\n");
                } else {
                    printf("Current string comes after the entered string alphabetically.\n");
                }
                break;
            case 9:
                printf("Enter new base string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';
                break;
            case 10:
                printf("Exiting String OS. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 10);

    return 0;
}
