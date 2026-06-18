#include <stdio.h>

int main() {
    int arr1[50], arr2[50], merged[100];
    int size1, size2, i;

    printf("Enter the size of the first array: ");
    scanf("%d", &size1);

    printf("Enter %d elements for the first array:\n", size1);
    for(i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the size of the second array: ");
    scanf("%d", &size2);

    printf("Enter %d elements for the second array:\n", size2);
    for(i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    for(i = 0; i < size1; i++) {
        merged[i] = arr1[i];
    }

    for(i = 0; i < size2; i++) {
        merged[size1 + i] = arr2[i];
    }

    printf("The merged array is:\n");
    for(i = 0; i < size1 + size2; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}
