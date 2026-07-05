#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 100

struct Employee {
    int id;
    char name[50];
    char department[50];
    float salary;
};

struct Employee employees[MAX_EMPLOYEES];
int totalEmployees = 0;

void addEmployee() {
    if (totalEmployees >= MAX_EMPLOYEES) {
        printf("\nSystem is full. Cannot add more employees.\n");
        return;
    }

    struct Employee emp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);

    for (int i = 0; i < totalEmployees; i++) {
        if (employees[i].id == emp.id) {
            printf("\nError: ID already exists.\n");
            return;
        }
    }

    printf("Enter Name: ");
    scanf(" %[^\n]s", emp.name);
    printf("Enter Department: ");
    scanf(" %[^\n]s", emp.department);
    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    employees[totalEmployees] = emp;
    totalEmployees++;
    printf("\nEmployee added successfully.\n");
}

void displayEmployees() {
    if (totalEmployees == 0) {
        printf("\nNo records found.\n");
        return;
    }

    printf("\n--- Employee List ---\n");
    printf("%-10s %-20s %-20s %-10s\n", "ID", "Name", "Department", "Salary");
    for (int i = 0; i < totalEmployees; i++) {
        printf("%-10d %-20s %-20s %-10.2f\n", employees[i].id, employees[i].name, employees[i].department, employees[i].salary);
    }
}

void searchEmployee() {
    if (totalEmployees == 0) {
        printf("\nNo records found to search.\n");
        return;
    }

    int id, found = 0;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < totalEmployees; i++) {
        if (employees[i].id == id) {
            printf("\nEmployee Found:\n");
            printf("ID: %d\nName: %s\nDepartment: %s\nSalary: %.2f\n", employees[i].id, employees[i].name, employees[i].department, employees[i].salary);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", id);
    }
}

void deleteEmployee() {
    if (totalEmployees == 0) {
        printf("\nNo records found to delete.\n");
        return;
    }

    int id, found = 0;
    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < totalEmployees; i++) {
        if (employees[i].id == id) {
            found = 1;
            for (int j = i; j < totalEmployees - 1; j++) {
                employees[j] = employees[j + 1];
            }
            totalEmployees--;
            printf("\nEmployee record deleted successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", id);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n*** Mini Employment Management System ***\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee\n");
        printf("4. Delete Employee\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                deleteEmployee();
                break;
            case 5:
                printf("\nExiting program.\n");
                exit(0);
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    }
    return 0;
}
