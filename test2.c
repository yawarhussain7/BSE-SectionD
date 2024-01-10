#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct account{
    int accountid;
    char name[40];
    float balance;
};

void createAccount();
void deposit();
void withdraw();
void checkBalance();
void displayAccountDetails();

int main()
{
    int chooice;
    do
    {
        printf("\nBanking Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Display Account Details\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &chooice);


        switch (chooice) {
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
    } while (chooice != 6);
    
}

void createAccount()
{
     FILE *file = fopen("accounts.txt", "a");
    struct account newAccount;

    printf("Enter account number: ");
    scanf("%d", &newAccount.accountid);

    printf("Enter name: ");
    scanf("%s", newAccount.name);

    printf("Enter initial balance: ");
    scanf("%f", &newAccount.balance);

    fprintf(file, "%d %s %.2f\n", newAccount.accountid, newAccount.name, newAccount.balance);
    fclose(file);

    printf("Account created successfully!\n");
}

void deposit(){

    FILE *read = fopen("acccount.txt","r");
    FILE *write = fopen("temp.txt","w");

    struct account current;
    int accountNumber;
    float amount;
    int found;



}