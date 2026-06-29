#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_rotation(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if (len1 != len2) {
        return 0;
    }

    int temp_len = len1 * 2 + 1;
    char *temp = (char *)malloc(temp_len);
    
    if (temp == NULL) {
        return 0;
    }

    strcpy(temp, s1);
    strcat(temp, s1);

    int result = 0;
    if (strstr(temp, s2) != NULL) {
        result = 1;
    }

    free(temp);
    return result;
}

int main() {
    char str1[] = "ABCD";
    char str2[] = "CDAB";

    if (is_rotation(str1, str2)) {
        printf("Strings are rotations of each other\n");
    } else {
        printf("Strings are not rotations of each other\n");
    }

    return 0;
}
