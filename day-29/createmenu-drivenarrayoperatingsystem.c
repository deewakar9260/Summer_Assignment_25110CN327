#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void create(int arr[], int *size);
void display(int arr[], int size);
void insert(int arr[], int *size);
void deleteElement(int arr[], int *size);
void search(int arr[], int size);

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice;

    while (1) {
        printf("\n--- ARRAY OPERATING SYSTEM ---\n");
        printf("1. Create Array\n");
        printf("2. Display Array\n");
        printf("3. Insert Element\n");
        printf("4. Delete Element\n");
        printf("5. Search Element\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                create(arr, &size);
                break;
            case 2:
                display(arr, size);
                break;
            case 3:
                insert(arr, &size);
                break;
            case 4:
                deleteElement(arr, &size);
                break;
            case 5:
                search(arr, size);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Please select between 1 and 6.\n");
        }
    }
    return 0;
}

void create(int arr[], int *size) {
    printf("Enter the number of elements: ");
    scanf("%d", size);
    if (*size > MAX_SIZE || *size < 0) {
        printf("Invalid size! Maximum allowed is %d.\n", MAX_SIZE);
        *size = 0;
        return;
    }
    printf("Enter %d elements:\n", *size);
    for (int i = 0; i < *size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Array created successfully.\n");
}

void display(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert(int arr[], int *size) {
    if (*size >= MAX_SIZE) {
        printf("Array Overflow! Cannot insert more elements.\n");
        return;
    }
    int element, position;
    printf("Enter element to insert: ");
    scanf("%d", &element);
    printf("Enter position (0 to %d): ", *size);
    scanf("%d", &position);

    if (position < 0 || position > *size) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*size)++;
    printf("Element inserted successfully.\n");
}

void deleteElement(int arr[], int *size) {
    if (*size == 0) {
        printf("Array Underflow! Nothing to delete.\n");
        return;
    }
    int position;
    printf("Enter position to delete (0 to %d): ", *size - 1);
    scanf("%d", &position);

    if (position < 0 || position >= *size) {
        printf("Invalid position!\n");
        return;
    }

    printf("Deleted element: %d\n", arr[position]);
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

void search(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    int element, found = 0;
    printf("Enter element to search: ");
    scanf("%d", &element);

    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            printf("Element found at position %d (index %d).\n", i + 1, i);
            found = 1;
        }
    }
    if (!found) {
        printf("Element not found in the array.\n");
    }
}
