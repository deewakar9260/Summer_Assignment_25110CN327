#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *in_file, *out_file;
    char c, next_c;
    int in_single_comment = 0;
    int in_multi_comment = 0;

    in_file = fopen("input.c", "r");
    out_file = fopen("output.c", "w");

    if (in_file == NULL || out_file == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    c = fgetc(in_file);
    while (c != EOF) {
        next_c = fgetc(in_file);

        // Single-line comment handling ( // )
        if (!in_multi_comment && !in_single_comment) {
            if (c == '/' && next_c == '/') {
                in_single_comment = 1;
            }
        }
        if (in_single_comment) {
            if (c == '\n') {
                in_single_comment = 0;
                fputc('\n', out_file); // Keep the newline
            }
            c = next_c;
            continue;
        }

        // Multi-line comment handling ( /* ... */ )
        if (!in_single_comment && !in_multi_comment) {
            if (c == '/' && next_c == '*') {
                in_multi_comment = 1;
            }
        }
        if (in_multi_comment) {
            if (c == '*' && next_c == '/') {
                in_multi_comment = 0;
                // Skip the next character ('/')
                c = fgetc(in_file); 
                continue;
            }
            c = next_c;
            continue;
        }

        // Write non-comment characters
        if (!in_single_comment && !in_multi_comment) {
            fputc(c, out_file);
        }

        c = next_c;
    }

    fclose(in_file);
    fclose(out_file);
    printf("Comments removed successfully. Output saved to output.c\n");
    return 0;
}
