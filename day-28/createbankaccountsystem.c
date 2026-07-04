#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int accountNumber;
    char name[50];
    double balance;
} Account;

Account bank[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("\nBank database is full!\n");
        return;
    }
    
    Account newAcc;
    printf("\nEnter Account Number: ");
    scanf("%d", &newAcc.accountNumber);
    
    for (int i = 0; i < accountCount; i++) {
        if (bank[i].accountNumber == newAcc.accountNumber) {
            printf("\nAccount number already exists!\n");
            return;
        }
    }
    
    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]s", newAcc.name);
    
    printf("Enter Initial Deposit Amount: ");
    scanf("%lf", &newAcc.balance);
    
    if (newAcc.balance < 0) {
        printf("\nInitial deposit cannot be negative!\n");
        return;
    }
    
    bank[accountCount] = newAcc;
    accountCount++;
    printf("\nAccount created successfully!\n");
}

void deposit() {
    int accNum;
    double amount;
    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);
    
    for (int i = 0; i < accountCount; i++) {
        if (bank[i].accountNumber == accNum) {
            printf("Enter Amount to Deposit: ");
            scanf("%lf", &amount);
            if (amount <= 0) {
                printf("\nInvalid deposit amount!\n");
                return;
            }
            bank[i].balance += amount;
            printf("\nSuccessfully deposited! New Balance: %.2f\n", bank[i].balance);
            return;
        }
    }
    printf("\nAccount not found!\n");
}

void withdraw() {
    int accNum;
    double amount;
    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);
    
    for (int i = 0; i < accountCount; i++) {
        if (bank[i].accountNumber == accNum) {
            printf("Enter Amount to Withdraw: ");
            scanf("%lf", &amount);
            if (amount <= 0) {
                printf("\nInvalid withdrawal amount!\n");
                return;
            }
            if (amount > bank[i].balance) {
                printf("\nInsufficient balance!\n");
                return;
            }
            bank[i].balance -= amount;
            printf("\nSuccessfully withdrawn! New Balance: %.2f\n", bank[i].balance);
            return;
        }
    }
    printf("\nAccount not found!\n");
}

void checkBalance() {
    int accNum;
    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);
    
    for (int i = 0; i < accountCount; i++) {
        if (bank[i].accountNumber == accNum) {
            printf("\n--- Account Details ---");
            printf("\nAccount Number: %d", bank[i].accountNumber);
            printf("\nHolder Name:    %s", bank[i].name);
            printf("\nCurrent Balance: %.2f\n", bank[i].balance);
            return;
        }
    }
    printf("\nAccount not found!\n");
}

int main() {
    int choice;
    do {
        printf("\n=== BANK ACCOUNT SYSTEM ===");
        printf("\n1. Create Account");
        printf("\n2. Deposit Money");
        printf("\n3. Withdraw Money");
        printf("\n4. Check Balance / Details");
        printf("\n5. Exit");
        printf("\nChoose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                printf("\nThank you for using the Bank Account System!\n");
                break;
            default:
                printf("\nInvalid option! Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}
