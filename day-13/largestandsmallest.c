#include <stdio.h>

int main() {
    int arr[100];
    int size;
    int i;
    int max;
    int min;

    printf("Enter the size of the array: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    max = arr[0];
    min = arr[0];

    for (i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    printf("Largest element: %d\n", max);
    printf("Smallest element: %d\n", min);

    return 0;
}
