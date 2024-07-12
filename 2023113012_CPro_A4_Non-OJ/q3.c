#include <stdio.h>
#include <stdlib.h>

//A Strucure to define a node in the linked list containing data and address fields
typedef struct Node{
    int data;
    struct Node* next;
}Node;

//Function to remove duplicates from the linked list of colors
void removeDuplicates(Node* head){
    Node* traverse=head;

    while (traverse!=NULL){
        //If the current node has the same color as the next node, then remove the next node
        if (traverse->next!=NULL && traverse->data==traverse->next->data){ 
            Node* temp=traverse->next;
            traverse->next=temp->next;
            free(temp);
        }

        //Else, move to the next node
        else
            traverse=traverse->next;
    }
}

//Function to print the colors in the linked list
void printColors(Node* head){
    while (head!=NULL){
        //If the current node is not the last node, then print the color and an arrow
        if (head->next!=NULL)
            printf("%d -> ",head->data);

        //Else, print the color
        else
            printf("%d",head->data);

        //Move to the next node
        head=head->next;
    }
    printf("\n");
}

int main(){
    int n;
    printf("Enter the number of colors in the list: ");
    scanf("%d", &n);

    //Create a linked list of colors
    Node* head=NULL;
    Node* traverse=NULL;

    printf("Enter the colors: ");
    for (int i=0; i<n; i++){
        int color;
        scanf("%d", &color);

        //Create a new node for the color
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = color;
        newNode->next = NULL;

        //If the linked list is empty, then make the new node as the head
        if (head==NULL){
            head=newNode;
            traverse=head;
        }

        //Else, add the new node to the end of the linked list
        else{  
            traverse->next=newNode;
            traverse=newNode;
        }
    }

    //Remove the duplicate colors from the linked list
    removeDuplicates(head);

    //Print the modified linked list
    printf("Modified Linked List: ");
    printColors(head);

    //Free the memory allocated for the linked list
    while (head!=NULL){
        Node* temp=head;
        head=head->next;
        free(temp);
    }

    return 0;
}
