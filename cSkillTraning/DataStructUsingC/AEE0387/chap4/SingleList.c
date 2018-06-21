/* File name: SingleList.c */
/* Version 4.0, June, 2017 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void insertFunction(void);
void sortFunction(void);
void deleteFunction(void);
void displayFunction(void);
void modifyFunction(void);

struct student {
    char name[20];
    int score;
    struct student *next;
};

struct student *ptr, *head, *current, *prev;

int main()
{
    head=(struct student *) malloc(sizeof(struct student));
    head->next=NULL;
    char option1;
    
    while(1)
    {
        printf("\n");
        printf("****************************************\n");
        printf("              1.insert\n");
        printf("              2.delete\n");
        printf("              3.display\n");
        printf("              4.modify\n");
        printf("              5.quit\n");
        printf("****************************************\n");
        printf("   Please enter your choice (1-5)...");
        option1=getchar();
        while(getchar()!='\n') continue;
        printf("\n");
        switch(option1)
        {
            case '1':
                insertFunction();
                break;
            case '2':
                deleteFunction();
                break;
            case '3':
                displayFunction();
                break;
            case '4':
                modifyFunction();
                break;
            case '5':
                printf("\n");
                return 0;
        }
    }
}

void insertFunction(void)
{
    char sTemp[4];
    ptr=(struct student *) malloc(sizeof(struct student));
    printf(" Student name : ");
    gets(ptr->name);
    printf(" Student score: ");
    gets(sTemp);
    ptr->score = atoi(sTemp);
    
    sortFunction();
}

/* 以分數高低由大到小排列 */
void sortFunction(void)
{
    //插入資料
    if (head->next==NULL) {
        head->next=ptr;
        ptr->next=NULL;
    }
    else {
        prev = head;
        current = head->next;
        while ((current != NULL) && (current->score > ptr->score)){
            prev = current;
            current = current->next;
        }
        ptr->next = current;
        prev->next = ptr;
    }
    
}

void deleteFunction(void)
{
    char delName[20];
    printf(" Delete student name: ");
    gets(delName);
    
    prev = head;
    current = head->next;
    while ((current != NULL) && (strcmp(current->name , delName)!=0)) {
        prev = current;
        current = current->next;
    }
    if (current != NULL) {
        prev->next = current->next;
        free(current);
        printf(" Student %s has been deleted\n",delName);
    }
    else
        printf(" Student %s not found\n",delName);
}

void modifyFunction(void)
{
    char nTemp[20],sTemp[4];
    printf(" Modify student name: ");
    gets(nTemp);
    prev = head;
    current=head->next;    
    while ((current != NULL) && (strcmp(current->name , nTemp)!=0)) {
        prev = current;
        current = current->next;
    }
    if (current != NULL) {
        printf(" **************************\n");
        printf("  Student name : %s\n",current->name);
        printf("  Student score: %d\n",current->score);
        printf(" **************************\n");
        printf(" Please enter new score: ");
        gets(sTemp);
        prev->next = current->next;
        free(current);
        //重新加入
        ptr=(struct student *) malloc(sizeof(struct student));
        strcpy(ptr->name, nTemp);
        ptr->score = atoi(sTemp);
        ptr->next = NULL;
        prev = head;
        current = head->next;
        while ((current != NULL) && (current->score > ptr->score)) {
            prev = current;
            current = current->next;
        }
        ptr->next = current;
        prev->next = ptr;
        printf(" Student %s has been modified\n",nTemp);
    }
    else
        printf(" Student %s not found\n",nTemp);
}

void displayFunction(void)
{
    int count=0;
    
    if(head->next == NULL) {
        printf(" No student record\n");
    }
    else {
        printf("  NAME                SCORE\n");
        printf(" ---------------------------\n");
        current=head->next;
        while(current != NULL) {
            printf("  %-20s %3d\n", current->name, current->score);
            count++;
            current=current->next;
            if(count % 20 == 0) getchar();
        }
        printf(" ---------------------------\n");
        printf(" Total %d record(s) found\n", count);
    }
}