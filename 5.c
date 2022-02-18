#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
} *head;

void create_list(int n);
void insertNodeAtNth();
void display_list();
int count();

int main(){
    int n, d;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    create_list(n);
    printf("Enter the integer you wish to insert: ");
    scanf("%d", &d);
    printf("Before inserting\n");
    display_list();
    insertNodeAtNth(d, n);
    printf("after inserting\n");
    int a=count();
    display_list();
    printf("number of nodes %d",a);
    return 0;
}

void create_list(int n){
    int i;
    struct node *newNode, *temp;

    head = (struct node*)malloc(sizeof(struct node));
    printf("Enter an integer: ");
    scanf("%d", &head->data);
    head->next = NULL;

    temp = head;
    for(i = 1; i < n; i++){
        newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter an integer: ");
        scanf("%d", &newNode->data);
        newNode->next= NULL;

        temp->next = newNode;
        temp = temp->next;
    }
}

void insertNodeAtNth(int data, int number){
    int i,position;
    if(number%2==1)
    {
        position=((number+1)/2);
    }
    else
    {
        position=(((number)/2)+1);
    }
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("memory could not be allocated\n");
    }else{
        newNode->data = data;
        newNode->next = NULL;

        temp = head;
        if(position == 1){
            newNode->next = head;
            head = newNode;
            return;
        }
        for(i = 2; i < position; i++)
        {
            temp = temp->next;

            if(temp == NULL)
            {
                break;
            }
        }
        if(temp != NULL){
            newNode->next = temp->next;
            temp->next = newNode;
        }else{
            printf("\n");
        }
    }
}

int count()
{
    struct node *temp;
    int f=0;
    temp=head;
    while(temp!=NULL)
    {
        f++;
        temp=temp->next;
    }
    return f;
}

void display_list(){
    struct node *temp;
    temp = head;
    while(temp){
        printf("%d", temp->data);
        if(temp->next){
            printf(" -> ");
        }else{
            printf("\n");
        }
        temp = temp->next;
    }
}
