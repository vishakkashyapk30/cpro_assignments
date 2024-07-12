#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MAXNAME 50

typedef enum Status{
    active,
    inactive
}Status;

typedef enum Account_Type{
    savings, //0
    current  //1
}Account_Type;

typedef struct AccountInfo{
    int account_number;
    Account_Type accountType;
    char name[MAXNAME];
    float balance;
}AccountInfo;

typedef struct AccountNode{
    int account_number;
    Status stat;
    AccountInfo* account;
    struct AccountNode *next;
}AccountNode;

typedef struct Bank{
    AccountNode *head;
    int account_count;
}Bank;

char* int_to_str_AccType(Account_Type accountType){
    switch(accountType){
        case savings:   
            return "savings";
        case current:
            return "current";
    }
}

Account_Type str_to_int_AccType(char *accountType){
    if(strcmp(accountType,"savings")==0)
        return savings;
    else if(strcmp(accountType,"current")==0)
        return current;
    else
        return -1;
}

Bank *starbank; //!global bank

AccountInfo* findAccount(Account_Type accountType, char* name){
    AccountNode *temp = starbank->head;
    while(temp!=NULL){
        if((temp->stat==active)&&(strcmp(temp->account->name,name)==0)&&(temp->account->accountType==accountType)){
            return temp->account;
        }
        temp = temp->next;
    }
    return NULL;
}

void createAccount(Account_Type accountType, char* name, float amount){

    if(findAccount((accountType),name)!=NULL){
        printf("INVALID: User already exists!\n");
        return;
    }

    AccountInfo *new_account = (AccountInfo*)malloc(sizeof(AccountInfo));

    new_account->accountType = accountType;
    new_account->balance = amount;
    strcpy(new_account->name,name);

    AccountNode* tail = starbank->head;

    while((tail->next!=NULL)&&(tail->stat==active))
        tail=tail->next;

    if(tail->stat==inactive){
        tail->account = new_account;
        new_account->account_number=tail->account_number;
        tail->stat = active;
        starbank->account_count++;
    }
    else{
        AccountNode *new_node = (AccountNode*)malloc(sizeof(AccountNode));
        new_node->account_number = tail->account_number+1;
        new_account->account_number=new_node->account_number;
        new_node->account = new_account;
        new_node->stat = active;
        new_node->next = NULL;
        tail->next = new_node;
        starbank->account_count++;
    }

    printf("\nAccount Number: %d\n",new_account->account_number);
    printf("Accounter Holder: %s\n",new_account->name);
    printf("Account Type: %s\n",int_to_str_AccType(new_account->accountType));
    printf("Balance: Rs %.2f\n",new_account->balance);
    
}

void deleteAccount(Account_Type accountType, char* name){
    AccountNode *temp = starbank->head;
    while(temp!=NULL){
        if((temp->stat==active)&&(findAccount(accountType,name)==temp->account)){
            temp->stat = inactive;
            starbank->account_count--;
            free(temp->account);
            printf("Account deleted successfully!\n");
            return;
        }
        temp = temp->next;
    }
    printf("INVALID: User does not exist!\n");
}

void lowBalanceAccounts(){
    AccountNode *temp = starbank->head;
    while(temp!=NULL){
        if((temp->stat==active)&&(temp->account->balance<100)){
            printf("Account Number: %d, Name: %s, Balance: %.2f\n",temp->account_number, temp->account->name, temp->account->balance);
        }
        temp = temp->next;
    }
}

void transaction(int account_number, float amount, int code){
    AccountNode *temp = starbank->head;
    while(temp!=NULL){
        if((temp->stat==active)&&(temp->account_number==account_number)){
            if(code==1){
                temp->account->balance += amount;
                printf("Updated balance is Rs %.2f.\n",temp->account->balance);
            }
            else if(code==0){
                if((temp->account->balance)-amount<100){
                    printf("The balance is insufficient for the specified withdrawal.\n");
                    return;
                }
                temp->account->balance -= amount;
                
            }
            return;
        }
        temp = temp->next;
    }
    printf("INVALID: User does not exist!\n");
}

void display(){
    AccountNode *temp = starbank->head;

    printf("Account Number\t Account Type\t Name\t Balance\n");
    printf("-------------------------------------------------\n");
    while(temp!=NULL){
        if(temp->stat==active){
            printf("%d\t\t %s\t %s\t %.2f\n",temp->account->account_number,int_to_str_AccType(temp->account->accountType),temp->account->name,temp->account->balance);
        }
        temp = temp->next;
    }
    printf("-------------------------------------------------\n");
}

int main(){
    starbank = (Bank*)malloc(sizeof(Bank));
    starbank->head = (AccountNode*)malloc(sizeof(AccountNode));
    starbank->head->account_number = 100;
    starbank->head->stat = inactive;
    starbank->head->next = NULL;
    starbank->account_count = 0;

    char choice[12];
    char name[MAXNAME];
    char accountType[8];
    float amount;

    while(1){
        scanf("%s",choice);

        if(strcmp(choice,"CREATE")==0){
            scanf("%s",accountType);
            
            if(str_to_int_AccType(accountType)==-1){
                printf("INVALID: Wrong account type!\n");
    
                printf("====================================\n");
                continue;
            }

            scanf("%s",name);
            scanf("%f",&amount);
            createAccount(str_to_int_AccType(accountType),name,amount);
        }

        else if(strcmp(choice,"DELETE")==0){
            scanf("%s",accountType);


            if(str_to_int_AccType(accountType)==-1){
                printf("INVALID: Wrong account type!");
                printf("====================================\n");
                continue;
            }

            scanf("%s",name);
            deleteAccount(str_to_int_AccType(accountType),name);
        }

        else if(strcmp(choice,"LOWBALANCE")==0)
            lowBalanceAccounts();
        
        else if(strcmp(choice,"TRANSACTION")==0){
            int account_number;
            float amount;
            int code;
            scanf("%d",&account_number);
            scanf("%f",&amount);
            scanf("%d",&code); //1 for deposit, 0 for withdraw
            transaction(account_number,amount,code);
        }

        else if(strcmp(choice,"DISPLAY")==0)
            display();

        else if(strcmp(choice,"EXIT")==0)
            exit(0);
        
        else
            printf("INVALID CHOICE\n");
        
        printf("====================================\n");
    }
    return 1;
}