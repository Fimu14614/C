#include <stdio.h>
#include <stdlib.h>
struct node
{
 int data;
 struct node *next;
} * head;
void createList(int n);
void displayList();
int search(int key);
void ins();
int main()
{
 int n, keyToSearch, index;
 printf("Enter number of node to create: ");
 scanf("%d", &n);
 createList(n);
 printf("\nData in list: \n");
 displayList();
 printf("\nEnter element to search: ");
 scanf("%d", &keyToSearch);
 index = search(keyToSearch);
 if (index >= 0)
 printf("%d found in the list at index %d\n", keyToSearch,index);
 else
 printf("%d not found in the list.\n", keyToSearch);
 ins(index);
 displayList();
 return 0;
}

void createList(int n)
{
 struct node *newNode, *temp;
 int data, i;
 head = malloc(sizeof(struct node));
 if (head == NULL)
 {
 printf("Unable to allocate memory. Exiting from app.");
 exit(0);
 }
 printf("Enter data of node 1: ");
 scanf("%d", &data);
 head->data = data;
 head->next = NULL;
 temp = head;
 for (i = 2; i <= n; i++)
 {
 newNode = malloc(sizeof(struct node));
 if (newNode == NULL)
 {
 printf("Unable to allocate memory. Exiting from app.");
 exit(0);
 }
 printf("Enter data of node %d: ", i);
 scanf("%d", &data);
 newNode->data = data;
 newNode->next = NULL;
 temp->next = newNode;
 temp = temp->next;
 }
}

void displayList()
{
 struct node *temp;
 if (head == NULL)
 {
 printf("List is empty.\n");
 return;
 }
 temp = head;
 while (temp != NULL)
 {
 printf("%d, ", temp->data);
 temp = temp->next;
 }
 printf("\n");
}

int search(int key)
{
 int index;
 struct node *curNode;
 index = 0;
 curNode = head;
 while (curNode != NULL && curNode->data != key)
 {
 index++;
 curNode = curNode->next;
 }
 return (curNode != NULL) ? index : -1;
}

void ins(int index)
{
    struct node *newNode, *temp;
    int i,data;
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL)
    {
        printf("memory could not be allocated\n");
    }
    else
    {
        printf("Enter new data");
        scanf("%d",&data);
        newNode->data = data;
        newNode->next = NULL;

        temp = head;
        //if(index == 0){
            //newNode->next = head;
            //head = newNode;
            //return;
        //}
        for(i = 1; i < index+1; i++)
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
        }
        else
        {
            printf("\n");
        }
    }
}
