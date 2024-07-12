#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for maximum number of accounts and account number range.
#define MAX_ACCOUNTS 100
#define ACCOUNT_NUMBER_MIN 100
#define ACCOUNT_NUMBER_MAX 999

typedef struct Account {
    int accountNumber;
    float balance;
    char holderName[50];
    AccountType type;
    AccountStatus status; // Added status to mark accounts as deleted.
} Account;

typedef struct Bank {
    Account* accounts[MAX_ACCOUNTS];
    int numAccounts;
} Bank;

typedef enum AccountType {
    SAVINGS,
    CURRENT
} AccountType;

typedef enum AccountStatus {
    ACTIVE,
    DELETED
} AccountStatus;

Bank* BANK;

char* accountTypeToString(AccountType type) {
    if (type == SAVINGS)
        return "Savings";
    else if (type == CURRENT) 
        return "Current";
    return "Unknown";
}

void openAccount(Bank* bank, Account* account) {
    if (findAccount(bank, account->accountNumber) != NULL) {
        printf("Account already exists.\n");
        return;
    }
    bank->accounts[bank->numAccounts] = account;
    bank->numAccounts++;
}


Account* findAccount(Bank* bank, int accountNumber) {
    for (int i = 0; i < bank->numAccounts; i++) {
        if (bank->accounts[i]->accountNumber == accountNumber)
            return bank->accounts[i];
    }
    return NULL;
}

void deleteAccount(Bank* bank, AccountType accountType, const char* name) {
    int found = 0;
    for (int i = 0; i < bank->numAccounts; i++) {
        if (bank->accounts[i]->status == ACTIVE &&
            bank->accounts[i]->type == accountType &&
            strcmp(bank->accounts[i]->holderName, name) == 0) {
            // Mark the account as deleted.
            bank->accounts[i]->status = DELETED;
            found = 1;
            break;
        }
    }
    
    if (found) {
        printf("Account deleted successfully.\n");
    } else {
        printf("Invalid: User does not exist\n");
    }
}

int getNextAvailableAccountNumber(Bank* bank) {
    // Look for the first available account number.
    for (int i = 0; i < bank->numAccounts; i++) {
        if (bank->accounts[i]->status == DELETED) {
            // Reuse the account number of a deleted account.
            bank->accounts[i]->status = ACTIVE;
            return bank->accounts[i]->accountNumber;
        }
    }

    // If no deleted accounts are available, find the next available account number.
    for (int accountNumber = ACCOUNT_NUMBER_MIN; accountNumber <= ACCOUNT_NUMBER_MAX; accountNumber++) {
        if (findAccount(bank, accountNumber) == NULL) {
            return accountNumber;
        }
    }

    // No available account numbers.
    printf("No available account numbers. Maximum account limit reached.\n");
    return -1;
}

void initializeAccount(Bank* bank) {
    Account* account = (Account*)malloc(sizeof(Account));

    // Find the next available account number.
    account->accountNumber = getNextAvailableAccountNumber(bank);

    // Check if an available account number was found.
    if (account->accountNumber == -1) {
        free(account);
        return;
    }

    printf("Enter the account type (0 for Savings, 1 for Current): ");
    scanf("%d", &account->type);

    printf("Enter the name of the account holder: ");
    scanf("%s", account->holderName);

    printf("Enter the balance: ");
    scanf("%f", &account->balance);

    account->status = ACTIVE;

    openAccount(bank, account);
}

void displayAccounts(Account* accounts[]) {
    int n = BANK->numAccounts;
    printf("------------------------------------------------------------------\n");
    printf("Account Number\tAccount Type\tName\tBalance\n");
    printf("------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        if (accounts[i]->status == ACTIVE) {
            printf("\t%d\t", accounts[i]->accountNumber);
            printf("%s\t", accountTypeToString(accounts[i]->type));
            printf("\t%s\t", accounts[i]->holderName);
            printf("%.2f\n", accounts[i]->balance);
        }
    }

    printf("------------------------------------------------------------------\n");
}

void lowBalanceAccounts(Account* accounts[]) {
    int n = BANK->numAccounts;
    for (int i = 0; i < n; i++) {
        if (accounts[i]->status == ACTIVE && accounts[i]->balance < 100) {
            printf("Account Number: %d, Name: %s\n", accounts[i]->accountNumber, accounts[i]->holderName);
        }
    }
}

int main() {
    BANK = (Bank*)malloc(sizeof(Bank));

    while (1) {
        printf("******************************************************************\n");
        printf("                     BAKUL NIVASE BANK\n");
        printf("******************************************************************\n");
        printf("1. Open New Account\n");
        printf("2. Display All Accounts\n");
        printf("3. Display Low Balance Accounts\n");
        printf("4. Transaction (Deposit/Withdrawal)\n");
        printf("5. Delete Account\n");
        printf("6. Exit\n");
        printf("*******************************************************************\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        int accountNum, amount;
        if (choice == 1) 
            initializeAccount(BANK);
        else if (choice == 2) 
            displayAccounts(BANK->accounts);
        else if (choice == 3)
            lowBalanceAccounts(BANK->accounts);
        else if (choice == 4) {
            int transactionType;
            printf("Enter the account number: ");
            scanf("%d", &accountNum);

            printf("Enter the transaction type (1 for Deposit, 0 for Withdrawal): ");
            scanf("%d", &transactionType);

            printf("Enter the amount: ");
            scanf("%f", &amount);

            transaction(accountNum, amount, transactionType);
        }
        else if (choice == 5) {
            // Delete an account.
            printf("Enter the account type (0 for Savings, 1 for Current): ");
            int accountType;
            scanf("%d", &accountType);

            printf("Enter the name to delete: ");
            char name[50];
            scanf("%s", name);

            deleteAccount(BANK, accountType, name);
        }
        else if (choice == 6)
            exit(0);
        else 
            printf("Invalid choice.\n");
    }

    return 0;
}
