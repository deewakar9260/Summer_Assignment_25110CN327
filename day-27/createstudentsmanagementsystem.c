#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    int rollNumber;
    char name[50];
    float gpa;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("\nError: System storage is full.\n");
        return;
    }

    int roll;
    printf("\nEnter Roll Number: ");
    scanf("%d", &roll);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == roll) {
            printf("Error: A student with Roll Number %d already exists.\n", roll);
            return;
        }
    }

    students[studentCount].rollNumber = roll;
    printf("Enter Name: ");
    getchar();
    fgets(students[studentCount].name, sizeof(students[studentCount].name), stdin);
    students[studentCount].name[strcspn(students[studentCount].name, "\n")] = '\0';

    printf("Enter GPA: ");
    scanf("%f", &students[studentCount].gpa);

    studentCount++;
    printf("Student record added successfully!\n");
}

void displayStudents() {
    if (studentCount == 0) {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n--------------------------------------------------\n");
    printf("%-15s %-25s %-10s\n", "Roll Number", "Name", "GPA");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%-15d %-25s %-10.2f\n", students[i].rollNumber, students[i].name, students[i].gpa);
    }
    printf("--------------------------------------------------\n");
}

void searchStudent() {
    if (studentCount == 0) {
        printf("\nNo student records available to search.\n");
        return;
    }

    int roll;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == roll) {
            printf("\nRecord Found:\n");
            printf("Roll Number: %d\n", students[i].rollNumber);
            printf("Name:        %s\n", students[i].name);
            printf("GPA:         %.2f\n", students[i].gpa);
            return;
        }
    }
    printf("Student with Roll Number %d not found.\n", roll);
}

void updateStudent() {
    if (studentCount == 0) {
        printf("\nNo student records available to update.\n");
        return;
    }

    int roll;
    printf("\nEnter Roll Number to update: ");
    scanf("%d", &roll);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == roll) {
            printf("\nCurrent Data - Name: %s, GPA: %.2f\n", students[i].name, students[i].gpa);
            
            printf("Enter New Name: ");
            getchar();
            fgets(students[i].name, sizeof(students[i].name), stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0';

            printf("Enter New GPA: ");
            scanf("%f", &students[i].gpa);

            printf("Student record updated successfully!\n");
            return;
        }
    }
    printf("Student with Roll Number %d not found.\n", roll);
}

void deleteStudent() {
    if (studentCount == 0) {
        printf("\nNo student records available to delete.\n");
        return;
    }

    int roll;
    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == roll) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("Student record deleted successfully!\n");
            return;
        }
    }
    printf("Student with Roll Number %d not found.\n", roll);
}

int main() {
    int choice;

    do {
        printf("\n=== STUDENT RECORD MANAGEMENT SYSTEM ===\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Student Records\n");
        printf("3. Search Student Record\n");
        printf("4. Update Student Record\n");
        printf("5. Delete Student Record\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                printf("\nExiting the program. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please choose a option between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}
