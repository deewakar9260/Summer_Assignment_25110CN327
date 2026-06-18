#include <stdio.h>

int main() {
    int arr1[] = {1, 2, 3, 2, 1};
    int arr2[] = {3, 4, 5, 2, 6};
    
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    int unionArr[100];
    int k = 0;
    
    for (int i = 0; i < size1; i++) {
        int exists = 0;
        for (int j = 0; j < k; j++) {
            if (unionArr[j] == arr1[i]) {
                exists = 1;
                break;
            }
        }
        if (!exists) {
            unionArr[k++] = arr1[i];
        }
    }
    
    for (int i = 0; i < size2; i++) {
        int exists = 0;
        for (int j = 0; j < k; j++) {
            if (unionArr[j] == arr2[i]) {
                exists = 1;
                break;
            }
        }
        if (!exists) {
            unionArr[k++] = arr2[i];
        }
    }
    
    printf("Union of the two arrays: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", unionArr[i]);
    }
    printf("\n");
    
    return 0;
}
