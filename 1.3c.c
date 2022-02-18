#include <stdio.h>
#include <stdlib.h>

typedef struct Employee{
    char name[100];
    int nid;
    int age;
    char occup[50];
    float account;
} Emp;

void add_info(Emp *emp);
void view_info(Emp emp[]);

int n = 10;

int main(){
    int i;
    Emp emp[n];
    for(i = 0; i < n; i++){
        add_info(&emp[i]);
    }
    view_info(emp);
    return 0;
}

void add_info(Emp *emp){
    printf("Enter the name of an employee: ");
    fflush(stdin);
    scanf("%[^\n]s", emp->name);
    printf("Enter the NID of an employee: ");
    fflush(stdin);
    scanf("%d", &emp->nid);
    printf("Enter the age of an employee: ");
    fflush(stdin);
    scanf("%d", &emp->age);
    printf("Enter the occupation of an employee: ");
    fflush(stdin);
    scanf("%[^\n]s", emp->occup);
    printf("Enter the account balance of an employee: ");
    fflush(stdin);
    scanf("%f", &emp->account);

    system("cls");
}

void view_info(Emp emp[]){
    system("cls");
    int i;
    float m_intrest, a_balance, a_balance2;
    printf("\n\n \t\t\t *******************  Employee Info.  ***********************\n\n");

    for(i = 0; i < n; i++){
        m_intrest = emp[i].account*(6.5/100);
        a_balance= emp[i].account+m_intrest*12;
        a_balance2 = a_balance*7;
        printf(" \t%-10s", emp[i].name);
        printf("\t%d", emp[i].nid);
        printf("\t%d", emp[i].age);
        printf("\t%-15s", emp[i].occup);
        printf("\t%.2f", emp[i].account);
        printf("\t%.2f", m_intrest);
        printf("\t%.2f", a_balance);
        printf("\t\ %.2f\n", a_balance2);
    }

}
