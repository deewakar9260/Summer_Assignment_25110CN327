#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    char designation[50];
    float salary;
};

void addEmployee() {
    FILE *fp = fopen("employees.dat", "ab");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    struct Employee emp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);
    getchar();
    printf("Enter Name: ");
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = 0;
    printf("Enter Designation: ");
    fgets(emp.designation, sizeof(emp.designation), stdin);
    emp.designation[strcspn(emp.designation, "\n")] = 0;
    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    fwrite(&emp, sizeof(struct Employee), 1, fp);
    fclose(fp);
    printf("Employee added successfully!\n");
}

void displayEmployees() {
    FILE *fp = fopen("employees.dat", "rb");
    if (fp == NULL) {
        printf("\nNo records found!\n");
        return;
    }
    struct Employee emp;
    printf("\n-------------------------------------------------------------------\n");
    printf("%-10s %-20s %-20s %-10s\n", "ID", "Name", "Designation", "Salary");
    printf("-------------------------------------------------------------------\n");
    while (fread(&emp, sizeof(struct Employee), 1, fp)) {
        printf("%-10d %-20s %-20s %-10.2f\n", emp.id, emp.name, emp.designation, emp.salary);
    }
    printf("-------------------------------------------------------------------\n");
    fclose(fp);
}

void searchEmployee() {
    FILE *fp = fopen("employees.dat", "rb");
    if (fp == NULL) {
        printf("\nNo records found!\n");
        return;
    }
    int id, found = 0;
    struct Employee emp;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &id);

    while (fread(&emp, sizeof(struct Employee), 1, fp)) {
        if (emp.id == id) {
            printf("\nRecord Found:\n");
            printf("ID: %d\n", emp.id);
            printf("Name: %s\n", emp.name);
            printf("Designation: %s\n", emp.designation);
            printf("Salary: %.2f\n", emp.salary);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Employee with ID %d not found.\n", id);
    }
    fclose(fp);
}

void updateEmployee() {
    FILE *fp = fopen("employees.dat", "rb+");
    if (fp == NULL) {
        printf("\nNo records found!\n");
        return;
    }
    int id, found = 0;
    struct Employee emp;
    printf("\nEnter Employee ID to update: ");
    scanf("%d", &id);

    while (fread(&emp, sizeof(struct Employee), 1, fp)) {
        if (emp.id == id) {
            printf("\nEnter New Name: ");
            getchar();
            fgets(emp.name, sizeof(emp.name), stdin);
            emp.name[strcspn(emp.name, "\n")] = 0;
            printf("Enter New Designation: ");
            fgets(emp.designation, sizeof(emp.designation), stdin);
            emp.designation[strcspn(emp.designation, "\n")] = 0;
            printf("Enter New Salary: ");
            scanf("%f", &emp.salary);

            fseek(fp, -sizeof(struct Employee), SEEK_CUR);
            fwrite(&emp, sizeof(struct Employee), 1, fp);
            found = 1;
            printf("Record updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Employee with ID %d not found.\n", id);
    }
    fclose(fp);
}

void deleteEmployee() {
    FILE *fp = fopen("employees.dat", "rb");
    if (fp == NULL) {
        printf("\nNo records found!\n");
        return;
    }
    FILE *temp = fopen("temp.dat", "wb");
    if (temp == NULL) {
        printf("Error creating temporary file!\n");
        fclose(fp);
        return;
    }
    int id, found = 0;
    struct Employee emp;
    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &id);

    while (fread(&emp, sizeof(struct Employee), 1, fp)) {
        if (emp.id == id) {
            found = 1;
        } else {
            fwrite(&emp, sizeof(struct Employee), 1, temp);
        }
    }
    fclose(fp);
    fclose(temp);

    remove("employees.dat");
    rename("temp.dat", "employees.dat");

    if (found) {
        printf("Employee record deleted successfully!\n");
    } else {
        printf("Employee with ID %d not found.\n", id);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n*** EMPLOYEE MANAGEMENT SYSTEM ***\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: updateEmployee(); break;
            case 5: deleteEmployee(); break;
            case 6: exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
