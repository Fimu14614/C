#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} * head;

void createList(int n);
void displayList();
void del();

int i;

int main()
{
    int n, keyToSearch, index;

    printf("Enter number of node to create: ");
    scanf("%d", &n);

    createList(n);
    int m;
    scanf("%d",&m);
    del(m);

    printf("\nData in list: \n");
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

    printf("Enter data of node 0: ");
    scanf("%d", &data);

    head->data = data;
    head->next = NULL;

    temp = head;

    for (i = 1; i < n; i++)
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

void del(int pos)
{
    struct node *temp,*del;
    temp=head;
    if(pos==0)
    {
        head=temp->next;
        free(temp);
        return;
    }
    for (int i=0; temp!=NULL && i<pos-1; i++)
    {
        temp=temp->next;
    }
    if (temp == NULL || temp->next == NULL)
         return;
    struct node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
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
