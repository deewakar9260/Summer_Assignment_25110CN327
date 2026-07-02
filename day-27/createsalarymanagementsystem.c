#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

typedef struct {
    int id;
    char name[50];
    double base_salary;
    double allowances;
    double deductions;
    double net_salary;
} Employee;

Employee employees[MAX_EMPLOYEES];
int employee_count = 0;

void calculate_net_salary(Employee *emp) {
    emp->net_salary = emp->base_salary + emp->allowances - emp->deductions;
}

void add_employee() {
    if (employee_count >= MAX_EMPLOYEES) {
        printf("\nSystem full. Cannot add more employees.\n");
        return;
    }

    Employee emp;
    printf("\nEnter Employee ID: ");
    if (scanf("%d", &emp.id) != 1) return;
    
    getchar(); 
    printf("Enter Name: ");
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = 0;

    printf("Enter Base Salary: ");
    if (scanf("%lf", &emp.base_salary) != 1) return;
    
    printf("Enter Allowances: ");
    if (scanf("%lf", &emp.allowances) != 1) return;
    
    printf("Enter Deductions: ");
    if (scanf("%lf", &emp.deductions) != 1) return;

    calculate_net_salary(&emp);
    employees[employee_count++] = emp;
    printf("\nEmployee added successfully!\n");
}

void display_employees() {
    if (employee_count == 0) {
        printf("\nNo employee records found.\n");
        return;
    }

    printf("\n=============================================");
    printf("\nID   Name        Base     Allow    Deduct   Net");
    printf("\n=============================================");
    for (int i = 0; i < employee_count; i++) {
        printf("\n%d   %-10s  %-7.2f  %-7.2f  %-7.2f  %-7.2f",
               employees[i].id, employees[i].name, employees[i].base_salary,
               employees[i].allowances, employees[i].deductions, employees[i].net_salary);
    }
    printf("\n=============================================\n");
}

void search_employee() {
    int id;
    printf("\nEnter Employee ID to search: ");
    if (scanf("%d", &id) != 1) return;

    for (int i = 0; i < employee_count; i++) {
        if (employees[i].id == id) {
            printf("\nRecord Found:");
            printf("\nID: %d", employees[i].id);
            printf("\nName: %s", employees[i].name);
            printf("\nBase Salary: %.2f", employees[i].base_salary);
            printf("\nAllowances: %.2f", employees[i].allowances);
            printf("\nDeductions: %.2f", employees[i].deductions);
            printf("\nNet Salary: %.2f\n", employees[i].net_salary);
            return;
        }
    }
    printf("\nEmployee ID %d not found.\n", id);
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Salary Management System ---");
        printf("\n1. Add Employee");
        printf("\n2. Display All Employees");
        printf("\n3. Search Employee");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1: add_employee(); break;
            case 2: display_employees(); break;
            case 3: search_employee(); break;
            case 4: exit(0);
            default: printf("\nInvalid option. Try again.\n");
        }
    }
    return 0;
}
