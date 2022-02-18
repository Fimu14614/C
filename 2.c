#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
} *head;

void create_list(int n);
void insertNodeAtNth(int data, int position);
void display_list();

int main(){
    int n, d;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    create_list(n);
    printf("Enter the integer you wish to insert: ");
    scanf("%d", &d);
    printf("Enter the position you wish to insert it at: ");
    scanf("%d", &n);
    printf("Before inserting\n");
    display_list();
    insertNodeAtNth(d, n);
    printf("after inserting\n");
    display_list();
    return 0;
}

void create_list(int n){
    int i;
    struct node *newNode, *temp;

    head = (struct node*)malloc(sizeof(struct node));
    printf("Enter an integer: ");
    scanf("%d", &head->data);
    head->link = NULL;

    temp = head;
    for(i = 1; i < n; i++){
        newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter an integer: ");
        scanf("%d", &newNode->data);
        newNode->link = NULL;

        temp->link = newNode;
        temp = temp->link;
    }
}

void insertNodeAtNth(int data, int position){
    int i;
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("memory could not be allocated\n");
    }else{
        newNode->data = data;
        newNode->link = NULL;

        temp = head;
        if(position == 1){
            newNode->link = head;
            head = newNode;
            return;
        }
        for(i = 2; i < position; i++){
            temp = temp->link;

            if(temp == NULL){
                break;
            }
        }
        if(temp != NULL){
            newNode->link = temp->link;
            temp->link = newNode;
        }else{
            printf("\n");
        }
    }
}

void display_list(){
    struct node *temp;
    temp = head;
    while(temp){
        printf("%d", temp->data);
        if(temp->link){
            printf(" -> ");
        }else{
            printf("\n");
        }
        temp = temp->link;
    }
}
