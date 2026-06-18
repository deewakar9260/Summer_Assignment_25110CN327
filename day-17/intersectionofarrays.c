#include <stdio.h>

void findIntersection(int arr1[], int size1, int arr2[], int size2, int result[], int *resSize) {
    *resSize = 0;
    
    for (int i = 0; i < size1; i++) {
        int isDuplicate = 0;
        for (int k = 0; k < i; k++) {
            if (arr1[i] == arr1[k]) {
                isDuplicate = 1;
                break;
            }
        }
        if (isDuplicate) {
            continue;
        }

        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                result[*resSize] = arr1[i];
                (*resSize)++;
                break;
            }
        }
    }
}

int main() {
    int arr1[] = {4, 9, 5, 4, 9};
    int arr2[] = {9, 4, 9, 8, 4};
    
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    int result[100];
    int resSize;
    
    findIntersection(arr1, size1, arr2, size2, result, &resSize);
    
    printf("Intersection: ");
    for (int i = 0; i < resSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    
    return 0;
}
