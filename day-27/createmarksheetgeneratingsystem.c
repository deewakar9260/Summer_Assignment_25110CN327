#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int rollNo;
    int marks[5];
    int total;
    float percentage;
    char division[20];
};

int main() {
    struct Student s;

    printf("Enter Student Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0';

    printf("Enter Roll Number: ");
    scanf("%d", &s.rollNo);

    s.total = 0;
    for (int i = 0; i < 5; i++) {
        do {
            printf("Enter marks for Subject %d (0-100): ", i + 1);
            scanf("%d", &s.marks[i]);
            if (s.marks[i] < 0 || s.marks[i] > 100) {
                printf("Invalid marks! Please enter a value between 0 and 100.\n");
            }
        } while (s.marks[i] < 0 || s.marks[i] > 100);
        s.total += s.marks[i];
    }

    s.percentage = s.total / 5.0;

    if (s.percentage >= 80) {
        strcpy(s.division, "First Class (Distinction)");
    } else if (s.percentage >= 60) {
        strcpy(s.division, "First Class");
    } else if (s.percentage >= 50) {
        strcpy(s.division, "Second Class");
    } else if (s.percentage >= 40) {
        strcpy(s.division, "Pass");
    } else {
        strcpy(s.division, "Fail");
    }

    printf("\n\n======================================\n");
    printf("           STUDENT MARKSHEET          \n");
    printf("======================================\n");
    printf("Name        : %s\n", s.name);
    printf("Roll Number : %d\n", s.rollNo);
    printf("--------------------------------------\n");
    for (int i = 0; i < 5; i++) {
        printf("Subject %d   : %d/100\n", i + 1, s.marks[i]);
    }
    printf("--------------------------------------\n");
    printf("Total Marks : %d/500\n", s.total);
    printf("Percentage  : %.2f%%\n", s.percentage);
    printf("Division    : %s\n", s.division);
    printf("======================================\n");

    return 0;
}
