#include <stdio.h>

int main() {
    int arr1[] = {1, 2, 4, 5, 6, 8, 9};
    int arr2[] = {2, 3, 5, 7, 8, 10};
    
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    printf("Common elements: ");
    
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                int isDuplicate = 0;
                for (int k = 0; k < i; k++) {
                    if (arr1[i] == arr1[k]) {
                        isDuplicate = 1;
                        break;
                    }
                }
                if (!isDuplicate) {
                    printf("%d ", arr1[i]);
                }
                break;
            }
        }
    }
    
    printf("\n");
    return 0;
}
