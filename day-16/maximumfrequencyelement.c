#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int arr[] = {4, 2, 8, 3, 2, 4, 1, 4, 3, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    qsort(arr, n, sizeof(int), compare);

    int max_freq = 0;
    int current_freq = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            current_freq++;
        } else {
            if (current_freq > max_freq) {
                max_freq = current_freq;
            }
            current_freq = 1;
        }
    }

    if (current_freq > max_freq) {
        max_freq = current_freq;
    }

    printf("Maximum frequency: %d\n", max_freq);

    return 0;
}
