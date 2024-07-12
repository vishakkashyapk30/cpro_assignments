#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME 50

typedef enum Status{
    active,
    inactive
} Status;

//0 for Savings, 1 for Current
typedef enum AccountType{
    savings, 
    current 
} AccountType;

typedef struct AccountInfo{
    int accountNumber;
    AccountType accountType;
    char name[MAX_NAME];
    float balance;
} AccountInfo;

typedef struct AccountNode{
    int accountNumber;
    Status accStatus;
    AccountInfo* account;
    struct AccountNode *next;
} AccountNode;

typedef struct Bank{
    AccountNode *head;
    int accountCount;
} Bank;

char* intToStrAccType(AccountType accountType) {
    if (accountType == savings) 
        return "savings";
    else if (accountType == current) 
        return "current";
}

AccountType strToIntAccType(char *accountType) {
    if (strcmp(accountType, "savings") == 0) 
        return savings;
    else if (strcmp(accountType, "current") == 0) 
        return current;
    else 
        return -1;
}

Bank* BANK; 

void display(){
    AccountNode *temp = BANK->head;

    printf("Account Number\t Account Type\t Name\t Balance\n");
    printf("-------------------------------------------------\n");
    while(temp!=NULL){
        if(temp->accStatus==active)
            printf("%d\t\t %s\t\t %s\t %.2f\n", temp->accountNumber, intToStrAccType(temp->account->accountType), temp->account->name, temp->account->balance);
        temp = temp->next;
    }  
    printf("-------------------------------------------------\n");
}

AccountInfo* findAccount(AccountType accountType, char* name) {
    AccountNode *temp = BANK->head;
    while (temp != NULL) {
        if ((temp->accStatus == active) && (strcmp(temp->account->name, name) == 0) && (temp->account->accountType == accountType)) {
            return temp->account;
        }
        temp = temp->next;
    }
    return NULL;
}

void createAccount(AccountType accountType, char *name, float amount){
    if(findAccount(accountType, name) != NULL) {
        printf("Inavlid:User Already Exists\n");
        return;
    }

    AccountInfo *newAccount = (AccountInfo*)malloc(sizeof(AccountInfo));

    newAccount->accountType = accountType;
    newAccount->balance = amount;
    strcpy(newAccount->name, name);

    AccountNode *start = BANK->head;

    while(start->next!=NULL && start->accStatus==active)
        start=start->next;

    if(start->accStatus==inactive){
        start->account = newAccount;
        newAccount->accountNumber = start->accountNumber; 
        start->accStatus = active;
        BANK->accountCount++;
        return;
    }

    else{
        AccountNode *newNode = (AccountNode*)malloc(sizeof(AccountNode));
        newNode->accountNumber = start->accountNumber;
        newAccount->accountNumber = start->accountNumber;
        newNode->account = newAccount;
        newNode->accStatus = active;
        newNode->next = NULL;
        start->next = newNode;
        BANK->accountCount++;
        return;
    }

    printf("Account Number: %d\n", newAccount->accountNumber);
    printf("Account Type: %s\n", intToStrAccType(newAccount->accountType));
    printf("Account Holder: %s\n", newAccount->name);
    printf("Account Balance: %.2f\n", newAccount->balance);
}

void deleteAccount(AccountType accountType, char *name) {
    AccountNode *temp = BANK->head;
    while(temp != NULL) {
        if ((temp->accStatus == active) && (findAccount(accountType, name) == temp->account)) {
            temp->accStatus = inactive;
            BANK->accountCount--;
            free(temp->account);
            printf("Account Deleted Successfully\n");
            return;
        }
        temp = temp->next;
    }
    printf("Invalid: User Does Not Exist\n");
}   

void lowBalanceAccounts(){
    AccountNode* temp = BANK->head;
    while(temp!=NULL){
        if(temp->accStatus==active && temp->account->balance<100){
            printf("Account Number: %d, Name: %s, Balance: %.2f\n", temp->accountNumber, temp->account->name, temp->account->balance);
        }
    }
}

void transaction(int accountNumber, float amount, int code){
    AccountNode *temp = BANK->head;
    while(temp!=NULL){
        if((temp->accStatus==active)&&(temp->accountNumber==accountNumber)){
            if(code==1){
                temp->account->balance+=amount;
                printf("Account Number: %d, Name: %s, Balance: %.2f\n", temp->accountNumber, temp->account->name, temp->account->balance);
                return;
            }
            else if(code==2){
                if(temp->account->balance<amount){
                    printf("Insufficient Balance\n");
                    return;
                }
                else{
                    temp->account->balance-=amount;
                    printf("Account Number: %d, Name: %s, Balance: %.2f\n", temp->accountNumber, temp->account->name, temp->account->balance);
                    return;
                }
            }
        }
        temp = temp->next;
    }
    printf("Invalid: User Does Not Exist\n");   
}

int main(){
    BANK = (Bank*)malloc(sizeof(Bank));
    BANK->head = (AccountNode*)malloc(sizeof(AccountNode));
    BANK->head->accountNumber = 100;
    BANK->head->accStatus = inactive;
    BANK->head->next = NULL;
    BANK->accountCount = 0;

    char ch[15];
    char name[MAX_NAME];
    char accountType[10];
    float amount;

    while(1){
        printf("====================================\n");
        printf("The Operations are:\n");
        printf("CREATE\n");
        printf("DELETE\n");
        printf("TRANSACTION\n");
        printf("LOWBALANCE\n");
        printf("DISPLAY\n");
        printf("EXIT\n");
        printf("====================================\n");

        scanf("%s", ch);

        if(strcmp(ch,"CREATE")==0){
            printf("Enter the account type (savings/current):\n");
            scanf("%s", accountType);

            if(strToIntAccType(accountType)==-1){
                printf("Invalid: Wrong Account Type\n");
                printf("====================================\n");
                continue;
            }

            printf("Enter the name:\n");
            scanf("%s", name);

            printf("Enter the amount:\n");
            scanf("%f", &amount);

            createAccount(strToIntAccType(accountType), name, amount);
        }

        else if(strcmp(ch, "DELETE")==0){
            printf("Enter the account type (savings/current):\n");
            scanf("%s", accountType);

            if(strToIntAccType(accountType)==-1){
                printf("Invalid: Wrong Account Type\n");
                printf("====================================\n");
                continue;
            }

            printf("Enter the name:\n");
            scanf("%s", name);

            deleteAccount(strToIntAccType(accountType), name);
        }

        else if(strcmp(strcmp, "TRANSACTION")==0){
            int accNum, code;
            float amt;

            printf("Enter the account number:\n");
            scanf("%d", &accNum);

            printf("Enter the amount:\n");
            scanf("%f", &amt);

            printf("Enter the code (1 for deposit, 0 for withdrawal):\n");
            scanf("%d", &code);

            transaction(accNum, amt, code);
        }

        else if(strcmp(ch, "LOWBALANCE")==0){
            lowBalanceAccounts();
        }

        else if(strcmp(ch, "DISPLAY")==0){
            display();
        }

        else if(strcmp(ch, "EXIT")==0){
            exit(0);
        }

        else{
            printf("Invalid Choice\n");
        }

        printf("====================================\n");

    }
    return 0;
}
    





