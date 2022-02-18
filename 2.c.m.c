#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
} *head;

void create_list(int n);
void insertNodeAtNth(int data, int position);
void firstnodedelete();
void deletenodenth();
void display_list();

int main(){
    int n, d,node;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    create_list(n);
    printf("Enter the data you wish to insert: ");
    scanf("%d", &d);
    printf("Enter the position you wish to insert it at: ");
    scanf("%d", &n);
    printf("Before inserting\n");
    display_list();
    insertNodeAtNth(d, n);
    printf("after inserting\n");
    display_list();
    printf("Enter the node you want to delete: ");
    scanf("%d",&node);
    if(node==1)
    {
        firstnodedelete();
    }
    else{
        deletenodenth(node);
    }
    printf("deleted node successfully\n");
    display_list();
    return 0;
}

void create_list(int n){
    int i;
    struct node *newNode, *temp;

    head = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data of node 1: ");
    scanf("%d", &head->data);
    head->link = NULL;

    temp = head;
    for(i = 2; i <=n; i++){
        newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data of node %d: ",i);
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
void firstnodedelete()
{
    struct node *firstnode;
    firstnode=head;
    head=head->link;
    free(firstnode);
}
void deletenodenth(int node)
{
    int i;
    struct node *prevnode,*currnode;
    prevnode=NULL;
    currnode=head;
    for(i=2;i<=node;i++)
    {
        prevnode=currnode;
        currnode=currnode->link;
        if(currnode==NULL)
            break;
    }
    if(currnode!=NULL)
    {
        prevnode->link=currnode->link;
        free(currnode);

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
