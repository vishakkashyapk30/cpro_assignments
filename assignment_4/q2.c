#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//A Strucure to define a node in the linked list containing data and address fields
typedef struct Node{
    float value;
    struct Node* next;
}Node;

//A ComplexNumber is a linked list of floats
typedef Node* ComplexNumber;

//Function to create a complex number
ComplexNumber createComplexNumber(int dimension){
    ComplexNumber head = (ComplexNumber)malloc(sizeof(Node));
    ComplexNumber traverse = head;
    //Loops through dimensions and creates node for each dimension
    while(dimension--){
        float val;
        scanf("%f",&val);
        traverse->value = val;
        traverse->next = (ComplexNumber)malloc(sizeof(Node));
        traverse = traverse->next;
    }
    traverse->next = NULL;
    return head;
}

//Function to print the complex number
void printComplexNumber(ComplexNumber num){
    printf("Result: ");
    //Loops through each linked list and prints the values
    while(num->next != NULL){
        printf("%.2f ",num->value);
        num = num->next;
    }
    printf("\n");
}

//Function to add two complex numbers
ComplexNumber add(ComplexNumber c1, ComplexNumber c2){
    ComplexNumber head = (ComplexNumber)malloc(sizeof(Node));
    ComplexNumber traverse = head;
    //Loops through the linked lists and performs the addition operation on the two complex numbers
    while(c1->next != NULL && c2->next != NULL){
        traverse->value = c1->value + c2->value;
        traverse->next = (ComplexNumber)malloc(sizeof(Node));
        traverse = traverse->next;
        c1 = c1->next;
        c2 = c2->next;
    }
    traverse->next = NULL;
    return head;
}

//Function to subtract two complex numbers
ComplexNumber sub(ComplexNumber c1, ComplexNumber c2){
    ComplexNumber head = (ComplexNumber)malloc(sizeof(Node));
    ComplexNumber traverse = head;
    //Loops through the linked lists and performs the subtraction operation on the two complex numbers
    while(c1->next != NULL && c2->next != NULL){
        traverse->value = c1->value - c2->value;
        traverse->next = (ComplexNumber)malloc(sizeof(Node));
        traverse = traverse->next;
        c1 = c1->next;
        c2 = c2->next;
    }
    traverse->next = NULL;
    return head;
}

//Function to find the dot product of two complex numbers
float dot(ComplexNumber c1, ComplexNumber c2){
    float sum = 0;
    //Loops through the linked list and performs the dot product operation on the two complex numbers
    while(c1->next != NULL && c2->next != NULL){
        sum += c1->value * c2->value;
        c1 = c1->next;
        c2 = c2->next;
    }
    return sum;
}

//Function to find the modulus of a complex number
float mod(ComplexNumber c){
    float sum = 0;
    //Loops through the complex number and calculates the sum to find the mod of the complex number
    while (c->next != NULL){
        sum += c->value * c->value;
        c = c->next;
    }
    return sqrtf(sum);
}

//Function to find the cosine similarity of two complex numbers
float cosineSimilarity(ComplexNumber c1, ComplexNumber c2){
    return dot(c1,c2) / (mod(c1) * mod(c2));
}

int main(){
    while(1){
        char ch[4];
        scanf("%s",ch);

        //Exit the program if the user enters -1
        if(strcmp(ch,"-1") == 0){
            printf("<Exit.>\n");
            return 0;
        }

        //Else, perform the operation
        else if(strcmp(ch,"ADD")==0){
            ComplexNumber c1,c2;

            int dimension;
            scanf("%d",&dimension);

            c1 = createComplexNumber(dimension);
            c2 = createComplexNumber(dimension);

            printComplexNumber(add(c1,c2));
        }

        else if(strcmp(ch,"SUB")==0){
            ComplexNumber c1,c2;

            int dimension;
            scanf("%d",&dimension);

            c1 = createComplexNumber(dimension);
            c2 = createComplexNumber(dimension);

            printComplexNumber(sub(c1,c2));
        }

        else if(strcmp(ch,"DOT")==0){ 
            ComplexNumber c1,c2;

            int dimension;
            scanf("%d",&dimension);

            c1 = createComplexNumber(dimension);
            c2 = createComplexNumber(dimension);

            printf("Result: %.2f\n",dot(c1,c2));
        }

        else if(strcmp(ch,"COSINE")==0){
            ComplexNumber c1,c2;

            int dimension;
            scanf("%d",&dimension);

            c1 = createComplexNumber(dimension);
            c2 = createComplexNumber(dimension);
            
            printf("Result: %.2f\n",cosineSimilarity(c1,c2));
        }

        else
            printf("Input not Valid\n");
    }

    return 0;
}