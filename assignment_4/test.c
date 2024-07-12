#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum Account_Type{
    savings,
    current
}Account_Type;

typedef struct AccountInfo{
    int Account_Number;
    Account_Type acc_type;
    char name[50];
    float balance;
}AccountInfo;

typedef struct Bank{
    AccountInfo* customers[100];
    int num_customers;
}Bank;

Bank* bank_of_iiit;

char* int_to_str_AccType(Account_Type acc_type){
    switch(acc_type){
        case savings:   
            return "savings";
        case current:
            return "current";
    }
}

AccountInfo* find_account(Bank* bank, int accountNumber){
    for(int i=0;i<bank->num_customers;i++){
        if(bank->customers[i]->Account_Number==accountNumber)
            return bank->customers[i];
    }
    return NULL;
}

void new_account(Bank* bank, AccountInfo* acc){
    if(find_account(bank,acc->Account_Number)!=NULL){
        printf("Account already exists.\n");
        return;
    }
    bank->customers[bank->num_customers]=acc;
    bank->num_customers++;
}

void initialise_account(Bank* bank){
    AccountInfo* acc=(AccountInfo*)malloc(sizeof(AccountInfo));

    printf("Enter the account number: ");
    scanf("%d",&acc->Account_Number);

    printf("Enter the account type (0 for savings, 1 for current): ");
    scanf("%d",&acc->acc_type);

    printf("Enter the name of the account holder: ");
    scanf("%s",acc->name);
     

    printf("Enter the balance: ");
    scanf("%f",&acc->balance);

    new_account(bank,acc);
}

//QUESTION 1: WRITE A DISPLAY FUNCTION
void display(AccountInfo* accounts[]){
    int n=bank_of_iiit->num_customers;
    printf("------------------------------------------------------------------\n");
    printf("Account Number\tAccount Type\tName\tBalance\n");
    printf("------------------------------------------------------------------\n");

    for(int i=0;i<n;i++){
        printf("\t%d\t",accounts[i]->Account_Number);
        printf("%s\t",int_to_str_AccType(accounts[i]->acc_type));
        printf("\t%s\t",accounts[i]->name);
        printf("%.2f\n",accounts[i]->balance);   
    }

    printf("------------------------------------------------------------------\n");
}

//QUESTION 2:WRITE A LOWBALANCEACCOUNTS FUNCTION
void lowBalanceAccounts(AccountInfo* accounts[]){
    int n=bank_of_iiit->num_customers;
    for(int i=0;i<n;i++){
        if(accounts[i]->balance<100){
            printf("Account Number: %d, Name: %s\n",accounts[i]->Account_Number, accounts[i]->name);
        }
    }
}

//QUESTION 3: WRITE A FUNCTION NAMED TRANSACTION
void transaction(int accountNumber, float amount, int code){
    int found=0;
    int acc_index;
    for(int i=0;i<100;i++){
        if(bank_of_iiit->customers[i]->Account_Number==accountNumber){
            found=1;
            acc_index=i;
            break;
        }
    }

    if(found){
        if(code){
            int final_amount=(bank_of_iiit->customers[acc_index]->balance)+amount;
            bank_of_iiit->customers[acc_index]->balance=final_amount;
        }
        else{
            int final_amount=(bank_of_iiit->customers[acc_index]->balance)-amount;

            if(final_amount<100)
                printf("The balance is insufficient for the specified withdrawal.\n");
            else
               bank_of_iiit->customers[acc_index]->balance=final_amount;
        }
    }
    else printf("ACCOUNT NOT FOUND.\n");
}

int main(){
    bank_of_iiit=(Bank*)malloc(sizeof(Bank));

    while(1){
        printf("==================================================================\n");
        printf("                     BANK OF IIIT-HYDERABAD\n");
        printf("==================================================================\n");
        printf("1. Create a new account\n");
        printf("2. Display all accounts\n");
        printf("3. Display low balance accounts\n");
        printf("4. Deposit\n");
        printf("5. Withdraw\n");
        printf("6. Exit\n");
        printf("==================================================================\n");
        
        int choice;
        printf("Enter your choice: ");
        scanf("%d",&choice);
         

        int acc_num,amount;
        switch(choice){
            case 1:
                initialise_account(bank_of_iiit);
                break;
            case 2:
                display(bank_of_iiit->customers);
                break;
            case 3:
                lowBalanceAccounts(bank_of_iiit->customers);
                break;
            case 4:
                printf("Enter the account number: ");
                scanf("%d",&acc_num);
                 

                printf("Enter the amount to be deposited: ");
                scanf("%f",&amount);
                 

                transaction(acc_num,amount,1);
                break;
            case 5:
                printf("Enter the account number: ");
                scanf("%d",&acc_num);
                 

                printf("Enter the amount to be withdrawn: ");
                scanf("%f",&amount);
                 

                transaction(acc_num,amount,0);
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}