#include <stdio.h>
#include <stdlib.h>

typedef struct Shopkeeper{
    char name[50];
    int nid;
    int age;
    char shop_adr[100];
    float daily_sales[30];
    float daily_rev[30];
} Shop;

void add_info(Shop *month);
void view_info(Shop *month);

int n = 30;

int main(){
    int i;
    Shop month_1;

    add_info(&month_1);
    view_info(&month_1);

    return 0;
}

void add_info(Shop *month){
    int i;
    printf("Enter the name of the Shopkeeper: ");
    fflush(stdin);
    scanf("%[^\n]s", month->name);
    printf("Enter the NID of the Shopkeeper: ");
    fflush(stdin);
    scanf("%d", &month->nid);
    printf("Enter the age of the Shopkeeper: ");
    fflush(stdin);
    scanf("%d", &month->age);
    printf("Enter the Shop address: ");
    fflush(stdin);
    scanf("%[^\n]s", month->shop_adr);

    for(i = 1; i <= n; i++){
        printf("Enter sales of day %d: ", i);
        scanf("%f", &month->daily_sales[i]);
        printf("Enter revenue of day %d: ", i);
        scanf("%f", &month->daily_rev[i]);
        printf("\n");
    }
    system("cls");
}

void view_info(Shop *month){
    system("cls");
    int i;
    float m_total = 0;
    printf("\n\n \t\t\t *************  Revenue Record  *******************\n\n");
    printf("\t \t\t\t Name: %s\n", month->name);
    printf("\t \t\t\t NID: %d\n", month->nid);
    printf("\t \t\t\t Age: %d\n", month->age);
    printf("\t \t\t\t Shop Address: %s\n\n", month->shop_adr);
    printf("\t \t\t\t Accounts\n");
    printf(" \t\t\t -----------------------------------------------------------\n");
    printf("\t \t\t\t Daily Sales\t\tDaily Revenue\n");
    for(i = 1; i <= n; i++){
        printf("\t \t\t\t %.2f units\t\t%.2f taka\n", month->daily_sales[i], month->daily_rev[i]);
        m_total+= month->daily_rev[i];
    }
    printf(" \t\t\t ___________________________________________________\n");
    printf("\t \t\t\t Monthly Total: %.2f\n", m_total);

}
