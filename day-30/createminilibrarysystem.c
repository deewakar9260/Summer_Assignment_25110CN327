#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    int id;
    char title[100];
    char author[100];
    float price;
};

struct Book library[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("\nLibrary is full! Cannot add more books.\n");
        return;
    }

    struct Book b;
    printf("\nEnter Book ID: ");
    scanf("%d", &b.id);
    getchar();

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == b.id) {
            printf("Error: A book with this ID already exists.\n");
            return;
        }
    }

    printf("Enter Book Title: ");
    fgets(b.title, sizeof(b.title), stdin);
    b.title[strcspn(b.title, "\n")] = '\0';

    printf("Enter Author Name: ");
    fgets(b.author, sizeof(b.author), stdin);
    b.author[strcspn(b.author, "\n")] = '\0';

    printf("Enter Book Price: ");
    scanf("%f", &b.price);

    library[bookCount] = b;
    bookCount++;
    printf("Book added successfully!\n");
}

void displayBooks() {
    if (bookCount == 0) {
        printf("\nNo books available in the library.\n");
        return;
    }

    printf("\n%-10s %-30s %-30s %-10s\n", "Book ID", "Title", "Author", "Price");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%-10d %-30s %-30s $%-9.2f\n", library[i].id, library[i].title, library[i].author, library[i].price);
    }
}

void searchBook() {
    if (bookCount == 0) {
        printf("\nNo books available to search.\n");
        return;
    }

    int searchId;
    printf("\nEnter Book ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == searchId) {
            printf("\nBook Found:\n");
            printf("ID: %d\n", library[i].id);
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Price: $%.2f\n", library[i].price);
            return;
        }
    }
    printf("Book with ID %d not found.\n", searchId);
}

int main() {
    int choice;

    while (1) {
        printf("\n=== MINI LIBRARY SYSTEM ===\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                printf("\nExiting system. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please enter a number between 1 and 4.\n");
        }
    }
    return 0;
}
