#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50
#define NAME_LENGTH 50

int id_array[MAX_STUDENTS];
char name_array[MAX_STUDENTS][NAME_LENGTH];
float gpa_array[MAX_STUDENTS];
int student_count = 0;

void add_student() {
    if (student_count >= MAX_STUDENTS) {
        printf("\nDatabase is full.\n");
        return;
    }
    printf("\nEnter Student ID: ");
    scanf("%d", &id_array[student_count]);
    getchar();
    printf("Enter Student Name: ");
    fgets(name_array[student_count], NAME_LENGTH, stdin);
    name_array[student_count][strcspn(name_array[student_count], "\n")] = '\0';
    printf("Enter Student GPA: ");
    scanf("%f", &gpa_array[student_count]);
    student_count++;
    printf("\nStudent added successfully!\n");
}

void display_students() {
    if (student_count == 0) {
        printf("\nNo student records found.\n");
        return;
    }
    printf("\n--- Student Records ---\n");
    for (int i = 0; i < student_count; i++) {
        printf("ID: %d | Name: %s | GPA: %.2f\n", id_array[i], name_array[i], gpa_array[i]);
    }
}

void search_student() {
    if (student_count == 0) {
        printf("\nNo records to search.\n");
        return;
    }
    char search_name[NAME_LENGTH];
    getchar();
    printf("\nEnter student name to search: ");
    fgets(search_name, NAME_LENGTH, stdin);
    search_name[strcspn(search_name, "\n")] = '\0';
    int found = 0;
    for (int i = 0; i < student_count; i++) {
        if (strcmp(name_array[i], search_name) == 0) {
            printf("\nStudent Found!\n");
            printf("ID: %d | Name: %s | GPA: %.2f\n", id_array[i], name_array[i], gpa_array[i]);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nStudent not found.\n");
    }
}

int main() {
    int choice;
    do {
        printf("\n=== Mini Project Menu ===\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Name\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                display_students();
                break;
            case 3:
                search_student();
                break;
            case 4:
                printf("\nExiting program.\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    } while (choice != 4);
    return 0;
}
