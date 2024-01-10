#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
    int accountNumber;
    char name[50];
    float balance;
};

void createAccount();
void deposit();
void withdraw();
void checkBalance();
void displayAccountDetails();

int main() {
    int choice;

    do {
        printf("\nBanking Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Display Account Details\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
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
                displayAccountDetails();
                break;
            case 6:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 6);

    return 0;
}

void createAccount() {
    FILE *file = fopen("accounts.txt", "a");
    struct Account newAccount;

    printf("Enter account number: ");
    scanf("%d", &newAccount.accountNumber);

    printf("Enter name: ");
    scanf("%s", newAccount.name);

    printf("Enter initial balance: ");
    scanf("%f", &newAccount.balance);

    fprintf(file, "%d %s %.2f\n", newAccount.accountNumber, newAccount.name, newAccount.balance);
    fclose(file);

    printf("Account created successfully!\n");
}

void deposit() {
    FILE *file = fopen("accounts.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");
    struct Account currentAccount;
    int accountNumber;
    float amount;
    int found = 0;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    while (fscanf(file, "%d %s %f", &currentAccount.accountNumber, currentAccount.name, &currentAccount.balance) != EOF) {
        if (currentAccount.accountNumber == accountNumber) {
            found = 1;
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            currentAccount.balance += amount;
        }
        fprintf(tempFile, "%d %s %.2f\n", currentAccount.accountNumber, currentAccount.name, currentAccount.balance);
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove("accounts.txt");
        rename("temp.txt", "accounts.txt");
        printf("Deposit successful!\n");
    } else {
        remove("temp.txt");
        printf("Account not found!\n");
    }
}

void withdraw() {
    FILE *file = fopen("accounts.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");
    struct Account currentAccount;
    int accountNumber;
    float amount;
    int found = 0;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    while (fscanf(file, "%d %s %f", &currentAccount.accountNumber, currentAccount.name, &currentAccount.balance) != EOF) {
        if (currentAccount.accountNumber == accountNumber) {
            found = 1;
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount <= currentAccount.balance) {
                currentAccount.balance -= amount;
                printf("Withdrawal successful!\n");
            } else {
                printf("Insufficient balance!\n");
            }
        }
        fprintf(tempFile, "%d %s %.2f\n", currentAccount.accountNumber, currentAccount.name, currentAccount.balance);
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove("accounts.txt");
        rename("temp.txt", "accounts.txt");
    } else {
        remove("temp.txt");
        printf("Account not found!\n");
    }
}

void checkBalance() {
    FILE *file = fopen("accounts.txt", "r");
    struct Account currentAccount;
    int accountNumber;
    int found = 0;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    while (fscanf(file, "%d %s %f", &currentAccount.accountNumber, currentAccount.name, &currentAccount.balance) != EOF) {
        if (currentAccount.accountNumber == accountNumber) {
            found = 1;
            printf("Balance for account %d: $%.2f\n", currentAccount.accountNumber, currentAccount.balance);
        }
    }

    fclose(file);

    if (!found) {
        printf("Account not found!\n");
    }
}

void displayAccountDetails() {
    FILE *file = fopen("accounts.txt", "r");
    struct Account currentAccount;

    printf("\nAccount Details\n");
    printf("----------------------------\n");
    printf("Account Number  |  Name  |  Balance\n");
    printf("----------------------------\n");

    while (fscanf(file, "%d %s %f", &currentAccount.accountNumber, currentAccount.name, &currentAccount.balance) != EOF) {
        printf("%-16d%-12s$%.2f\n", currentAccount.accountNumber, currentAccount.name, currentAccount.balance);
    }

    fclose(file);
}
