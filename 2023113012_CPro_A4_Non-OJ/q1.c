#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define an enumeration for account types
typedef enum AccountType{
    savings,
    current
}AccountType;

// Define a structure for account information
typedef struct AccountInfo{
    int account_number;
    AccountType type;
    char name[50];
    float balance;
}AccountInfo;

// Define a structure for a bank node
typedef struct AccountNode{
    AccountInfo data;
    struct AccountNode *next;
}AccountNode;

// Define an alias for the linked list
typedef AccountNode* LinkedList;

// Recursive Function to insert a new account into the linked list at a given position
LinkedList insert(AccountInfo account, int position, LinkedList list){
    // If the position is 0
    if (position == 0){
        AccountNode *newNode = (AccountNode *)malloc(sizeof(AccountNode));
        newNode->data = account;
        newNode->next = list;
        return newNode;
    } 
    
    // If the position is not 0
    else{
        list->next = insert(account, position - 1, list->next);
        return list;
    }
}

// Function to convert an account type enumeration to a string
const char* accountTypeToStr(AccountType type){
    if (type == savings)
        return "savings";
    
    else if (type == current)
        return "current";
    
    else
        return "Unknown";
}


// Function to create a new account and add it to the linked list
LinkedList createAccount(AccountType accountType, const char* name, float amount, LinkedList list){
    LinkedList original = list;
    AccountInfo *accountInfo = (AccountInfo *)malloc(sizeof(AccountInfo));
    LinkedList newNode = (LinkedList)malloc(sizeof(AccountNode));

    // Check if an account with the same type and name already exists
    LinkedList check = list;
    while (check != NULL){
        // If the account already exists
        if (check->data.type == accountType && strcmp(check->data.name, name) == 0) {
            printf("Account already exists\n");
            return original;
        }
        check = check->next;
    }

    // Check if the list is empty
    if (list == NULL){
        // Create a new account
        accountInfo->account_number = 100;
        accountInfo->type = accountType;
        strcpy(accountInfo->name, name);
        accountInfo->balance = amount;

        // Create a new node for the account
        newNode->data = *accountInfo;
        newNode->next = NULL;
        original = newNode;
    } 
    
    // If the list is not empty
    else{
        LinkedList prev = list;
        int count = 0;
        int flag = 0;

        // Check if the account number is already taken
        while (prev != NULL){
            // If the account number is taken
            if (prev->data.account_number != 100 + count) {
                flag = 1;
                break;
            }
            prev = prev->next;
            count++;
        }

        // If the account number is not taken
        if (flag == 0){
            // Traverse the list to find the last node
            while (list != NULL) {
                newNode = list;
                list = list->next;
            }
            // Create a new account
            accountInfo->account_number = 100 + count;
            accountInfo->type = accountType;
            strcpy(accountInfo->name, name);
            accountInfo->balance = amount;

            // Create a new node for the account
            newNode->next = (LinkedList)malloc(sizeof(AccountNode));
            newNode = newNode->next;
            newNode->data = *accountInfo;
            newNode->next = NULL;
        } 
        
        // If the account number is taken
        else{
            // Create a new account
            accountInfo->account_number = 100 + count;
            accountInfo->type = accountType;
            strcpy(accountInfo->name, name);
            accountInfo->balance = amount;

            // Create a new node for the account
            newNode->data = *accountInfo;
            newNode->next = NULL;
            original = insert(*accountInfo, count, original);
        }
    }
    // Print the account details
    printf("Account Number: %d\n", newNode->data.account_number);
    printf("Account Holder: %s\n", newNode->data.name);
    printf("Account Type: %s\n", accountTypeToStr(newNode->data.type));
    printf("Balance: Rs %.2f\n\n", newNode->data.balance);

    return original;
}

// Function to delete an account
LinkedList deleteAccount(AccountType accountType, const char* name, LinkedList list){
    // Check if the list is empty
    if (list == NULL){
        printf("Invalid: User does not exist\n");
        return list;
    }

    int found = 0;
    LinkedList prev = NULL;
    LinkedList current = list;

    // Traverse the list to find the account to be deleted
    while (current != NULL){
        // If the account is found
        if (current->data.type == accountType && strcmp(current->data.name, name) == 0) {
            found = 1;
            // If the account is the first element
            if (prev == NULL){
                // The first element is to be deleted
                list = current->next;
            }
            // If the account is not the first element
            else 
                prev->next = current->next;
            
            free(current); // Free the memory
            printf("Account deleted successfully\n");
            break;
        }
        prev = current;
        current = current->next;
    }

    // If the account was not found
    if (found == 0)
        printf("Invalid: User does not exist\n");

    return list;
}

// Function to perform a transaction on an account
void transaction(int accountNumber, float amount, int code, LinkedList list){
    // Check if the list is empty
    if (list == NULL){
        printf("Invalid: User does not exist\n");
        return;
    }

    int found = 0;

    // Traverse the list to find the account to be deleted
    while (list != NULL){
        // If the account is found
        if (list->data.account_number == accountNumber){
            found = 1;
            // Check if the code is valid
            if (code == 1) {
                list->data.balance += amount;
                printf("Updated Balance is Rs %.2f\n", list->data.balance);
            } 
            
            // If the code is invalid
            else if (code == 0){
                // Check if the balance is sufficient
                if (list->data.balance - amount < 100)
                    printf("The balance is insufficient for the specified withdrawal.\n");

                // If the balance is sufficient
                else {
                    list->data.balance -= amount;
                    printf("Updated Balance is Rs %.2f\n", list->data.balance);
                }
            }
            break;
        } 
        // If the account is not found
        else
            list = list->next;  
    }
    // If the account was not found
    if (found == 0)
        printf("Invalid: User does not exist\n");
    
}

// Function to display low balance accounts
void lowBalanceAccounts(LinkedList list){
    // Check if the list is empty
    int lowBalanceCount = 0;
    while (list != NULL){
        // If the balance is less than 100
        if (list->data.balance < 100){
            printf("Account Number: %d, Name: %s, Balance: %.2f\n", list->data.account_number, list->data.name, list->data.balance);
            lowBalanceCount++;
        }
        list = list->next;
    }
    // If all accounts have a balance greater than 100
    if (lowBalanceCount == 0)
        printf("No Low Balance Accounts Exist\n");
}
// Function to display all accounts in the linked list
void display(LinkedList list){
    // Check if the list is empty
    if (list == NULL)
        printf("No accounts to display\n");
    // If the list is not empty
    else{
        printf("------------------------------------------------\n");
        printf("Account Number\t\tAccount Type\tName\tBalance\n");
        printf("------------------------------------------------\n");
        while (list != NULL) {
            printf("%d\t\t%s\t%s\t%.2f\n", list->data.account_number, accountTypeToStr(list->data.type), list->data.name, list->data.balance);
            list = list->next;
        }
        printf("------------------------------------------------\n");
    }
}

int main(){
    LinkedList accountList = NULL;
    while(1){
        /*printf("-------------------------------------\n");
        printf("       Choices of Operations\n");
        printf("-------------------------------------\n");
        printf("CREATE\n");
        printf("DELETE\n");
        printf("TRANSACTION\n");
        printf("LOWBALANCE\n");
        printf("DISPLAY\n");
        printf("EXIT\n");
        printf("-------------------------------------\n");*/
        char choice[50];
        scanf("%s", choice);
        
        if (strcmp(choice, "CREATE") == 0){
            char accountTypeStr[10], name[50];
            float amount;

            //printf("Enter the account type (savings/current):\n");
            scanf("%s", accountTypeStr);

            //printf("Enter the name:\n");
            scanf("%s", name);

            //printf("Enter the amount:\n");
            scanf("%f", &amount);

            AccountType accountType;
            if(strcmp(accountTypeStr, "savings") == 0)
                accountType = savings;
            
            else if(strcmp(accountTypeStr, "current") == 0)
                accountType = current;
            
            else{
                printf("Invalid account type\n");
                continue;
            }

            accountList = createAccount(accountType, name, amount, accountList);
        } 
        
        else if (strcmp(choice, "DELETE") == 0){
            char accountTypeStr[10],name[50];
            
            //printf("Enter the account type (savings/current):\n");
            scanf("%s", accountTypeStr);

            //printf("Enter the name:\n");
            scanf("%s", name);

            AccountType accountType;
            if (strcmp(accountTypeStr, "savings") == 0)
                accountType = savings;
            
            else if (strcmp(accountTypeStr, "current") == 0)
                accountType = current;
            
            else{
                printf("Invalid account type\n");
                continue;
            }

            accountList = deleteAccount(accountType, name, accountList);
        }
        
        else if (strcmp(choice, "LOWBALANCE") == 0)
            lowBalanceAccounts(accountList);
        
        else if (strcmp(choice, "TRANSACTION") == 0){
            int accountNumber, code;
            float amount;

            //printf("Enter the account number:\n");
            scanf("%d", &accountNumber);

            //printf("Enter the amount:\n");
            scanf("%f", &amount);

            //printf("Enter the code (0 for Withdrawal/1 for Deposit):\n");
            scanf("%d", &code);

            transaction(accountNumber, amount, code, accountList);
        }

        else if (strcmp(choice, "DISPLAY") == 0)
            display(accountList);

        else if (strcmp(choice, "EXIT") == 0){
            // Free the memory and exit the program
            while (accountList != NULL){
                LinkedList temp = accountList;
                accountList = accountList->next;
                free(temp);
            }
            break;
        }

        else
            printf("Invalid choice\n");
    }
    
    return 0;
}
