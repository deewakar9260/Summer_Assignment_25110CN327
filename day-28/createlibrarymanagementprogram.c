#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    int id;
    char title[100];
    char author[100];
    int is_issued;
};

struct Book library[MAX_BOOKS];
int book_count = 0;

void addBook() {
    if (book_count >= MAX_BOOKS) {
        printf("\nLibrary is full.\n");
        return;
    }
    
    struct Book new_book;
    printf("\nEnter Book ID: ");
    scanf("%d", &new_book.id);
    getchar();
    
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == new_book.id) {
            printf("Error: A book with this ID already exists.\n");
            return;
        }
    }
    
    printf("Enter Book Title: ");
    fgets(new_book.title, sizeof(new_book.title), stdin);
    new_book.title[strcspn(new_book.title, "\n")] = '\0';
    
    printf("Enter Author Name: ");
    fgets(new_book.author, sizeof(new_book.author), stdin);
    new_book.author[strcspn(new_book.author, "\n")] = '\0';
    
    new_book.is_issued = 0;
    
    library[book_count] = new_book;
    book_count++;
    printf("Book added successfully!\n");
}

void displayBooks() {
    if (book_count == 0) {
        printf("\nNo books available in the library.\n");
        return;
    }
    
    printf("\n%-10s %-30s %-30s %-15s\n", "Book ID", "Title", "Author", "Status");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < book_count; i++) {
        printf("%-10d %-30s %-30s %-15s\n", 
               library[i].id, 
               library[i].title, 
               library[i].author, 
               library[i].is_issued ? "Issued" : "Available");
    }
}

void searchBook() {
    if (book_count == 0) {
        printf("\nNo books available to search.\n");
        return;
    }
    
    int search_id;
    printf("\nEnter Book ID to search: ");
    scanf("%d", &search_id);
    
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == search_id) {
            printf("\nBook Found:\n");
            printf("ID: %d\n", library[i].id);
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Status: %s\n", library[i].is_issued ? "Issued" : "Available");
            return;
        }
    }
    printf("Book with ID %d not found.\n", search_id);
}

void issueBook() {
    int issue_id;
    printf("\nEnter Book ID to issue: ");
    scanf("%d", &issue_id);
    
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == issue_id) {
            if (library[i].is_issued) {
                printf("Book is already issued to someone else.\n");
            } else {
                library[i].is_issued = 1;
                printf("Book issued successfully!\n");
            }
            return;
        }
    }
    printf("Book with ID %d not found.\n", issue_id);
}

void returnBook() {
    int return_id;
    printf("\nEnter Book ID to return: ");
    scanf("%d", &return_id);
    
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == return_id) {
            if (!library[i].is_issued) {
                printf("Book was not issued. It is already in the library.\n");
            } else {
                library[i].is_issued = 0;
                printf("Book returned successfully!\n");
            }
            return;
        }
    }
    printf("Book with ID %d not found.\n", return_id);
}

int main() {
    int choice;
    
    while (1) {
        printf("\n=== LIBRARY MANAGEMENT SYSTEM ===\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }
        
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
                issueBook();
                break;
            case 5:
                returnBook();
                break;
            case 6:
                printf("\nExiting system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
