#include <stdio.h>
#include <stdlib.h>

int main() {
    int pin = 1234;
    int enteredPin;
    int attempts = 0;
    int choice;
    float balance = 5000.0;
    float amount;
    int authenticated = 0;

    printf("=== WELCOME TO THE ATM SYSTEM ===\n");

    while (attempts < 3) {
        printf("Enter your 4-digit PIN: ");
        if (scanf("%d", &enteredPin) != 1) {
            printf("Invalid input format.\n\n");
            while (getchar() != '\n');
            attempts++;
            continue;
        }

        if (enteredPin == pin) {
            authenticated = 1;
            break;
        } else {
            attempts++;
            printf("Incorrect PIN. Attempts remaining: %d\n\n", 3 - attempts);
        }
    }

    if (!authenticated) {
        printf("Too many incorrect attempts. Your card has been blocked.\n");
        return 0;
    }

    while (1) {
        printf("\n=== ATM MAIN MENU ===\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid selection. Please try again.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("\nYour current balance is: $%.2f\n", balance);
                break;

            case 2:
                printf("\nEnter the amount to deposit: $");
                if (scanf("%f", &amount) != 1 || amount <= 0) {
                    printf("Invalid amount entered.\n");
                } else {
                    balance += amount;
                    printf("Successfully deposited $%.2f. New balance: $%.2f\n", amount, balance);
                }
                while (getchar() != '\n');
                break;

            case 3:
                printf("\nEnter the amount to withdraw: $");
                if (scanf("%f", &amount) != 1 || amount <= 0) {
                    printf("Invalid amount entered.\n");
                } else if (amount > balance) {
                    printf("Insufficient funds! Your current balance is $%.2f\n", balance);
                } else {
                    balance -= amount;
                    printf("Successfully withdrew $%.2f. Remaining balance: $%.2f\n", amount, balance);
                }
                while (getchar() != '\n');
                break;

            case 4:
                printf("\nThank you for using our ATM services. Goodbye!\n");
                exit(0);

            default:
                printf("\nInvalid option. Please choose a valid menu item.\n");
        }
    }

    return 0;
}
