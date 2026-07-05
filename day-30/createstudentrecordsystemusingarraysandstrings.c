#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

struct Student {
    int rollNumber;
    char name[NAME_LENGTH];
    float marks;
};

void addStudentRecord(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\nError: Record database is full.\n");
        return;
    }

    struct Student newStudent;
    printf("\nEnter Roll Number: ");
    scanf("%d", &newStudent.rollNumber);
    getchar();

    printf("Enter Name: ");
    fgets(newStudent.name, NAME_LENGTH, stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0';

    printf("Enter Marks: ");
    scanf("%f", &newStudent.marks);

    students[*count] = newStudent;
    (*count)++;
    printf("Student record added successfully!\n");
}

void displayAllRecords(const struct Student students[], int count) {
    if (count == 0) {
        printf("\nNo student records available to display.\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    printf("%-10s %-30s %-10s\n", "Roll No", "Name", "Marks");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-30s %-10.2f\n", students[i].rollNumber, students[i].name, students[i].marks);
    }
}

void searchStudentRecord(const struct Student students[], int count) {
    if (count == 0) {
        printf("\nNo student records available to search.\n");
        return;
    }

    int targetRoll;
    int found = 0;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &targetRoll);

    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == targetRoll) {
            printf("\nRecord Found:\n");
            printf("Roll Number: %d\n", students[i].rollNumber);
            printf("Name:        %s\n", students[i].name);
            printf("Marks:       %.2f\n", students[i].marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student record with Roll Number %d not found.\n", targetRoll);
    }
}

int main() {
    struct Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    do {
        printf("\n=== Student Record System ===\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Record by Roll Number\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudentRecord(students, &studentCount);
                break;
            case 2:
                displayAllRecords(students, studentCount);
                break;
            case 3:
                searchStudentRecord(students, studentCount);
                break;
            case 4:
                printf("\nExiting program.\n");
                break;
            default:
                printf("\nInvalid choice. Please select a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
