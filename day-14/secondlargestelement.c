#include <stdio.h>
#include <limits.h>

int main() {
    int arr[100];
    int size;
    int first;
    int second;

    printf("Enter size of the array: ");
    if (scanf("%d", &size) != 1 || size < 2) {
        printf("Invalid size. Array must have at least 2 elements.\n");
        return 1;
    }

    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    first = INT_MIN;
    second = INT_MIN;

    for (int i = 0; i < size; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] < first) {
            second = arr[i];
        }
    }

    if (second == INT_MIN) {
        printf("There is no distinct second largest element.\n");
    } else {
        printf("The second largest element is: %d\n", second);
    }

    return 0;
}
