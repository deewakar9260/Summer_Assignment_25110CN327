#include <stdio.h>

void removeSpaces(char *str) {
    int read = 0;
    int write = 0;

    while (str[read] != '\0') {
        if (str[read] != ' ') {
            str[write] = str[read];
            write++;
        }
        read++;
    }
    str[write] = '\0';
}

int main() {
    char text[] = " C   p r o g r a m   w i t h   s p a c e s ";

    printf("Original string: \"%s\"\n", text);

    removeSpaces(text);

    printf("Modified string: \"%s\"\n", text);

    return 0;
}
