/* File name : CircleList.c */
/* Version 4.0, June, 2017 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void insertFunction(void);    /* 插入函數 */
void sortFunction(void);      /* 排序函數 */
void deleteFunction(void);    /* 刪除函數 */
void displayFunction(void);   /* 輸出函數 */
void modifyFunction(void);    /* 修改函數 */

struct student {
    char name[20];        /* 姓名 */
    int score;            /* 分數 */
    struct student *next; /* 下一個鏈結 */
};

struct student *ptr, *head, *tail, *currentN, *prev;

int main()
{
    head=(struct student *) malloc(sizeof(struct student));
    head->next = head;
    char option1;
    
    while(1){
        printf("\n ****************************************\n");
        printf("               1.insert\n");
        printf("               2.delete\n");
        printf("               3.display\n");
        printf("               4.modify\n");
        printf("               5.quit\n");
        printf(" ****************************************\n");
        printf("   Please enter your choice (1-5)...");
        option1=getchar();
        while (getchar()!='\n') continue;
        switch(option1){
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
    
    ptr = (struct student *) malloc(sizeof(struct student));
    printf("\n Student name : ");
    gets(ptr->name);
    printf(" Student score: ");
    gets(sTemp);
    ptr->score = atoi(sTemp);
    sortFunction();
}
void sortFunction(void)
{
    //插入資料
    prev = head;
    currentN = head->next;
    if (currentN != head) {
        while ((currentN != head) && (currentN->score > ptr->score)){
            prev = currentN;
            currentN = currentN->next;
        }
    }
    ptr->next = currentN;
    prev->next = ptr;
}

void deleteFunction(void)
{
    char delName[20];
    int count = 0;
    
    printf("\n Delete student name: ");
    gets(delName);
    
    if(head->next == head) printf(" No student record\n");
    else{
        prev = head;
        currentN = head->next;
        while ((currentN != head) && (strcmp(currentN->name , delName)!=0)) {
            prev = currentN;
            currentN = currentN->next;
        }
        if (currentN != head){
            prev->next = currentN->next;
            free(currentN);
            printf(" Student %s has been deleted\n", delName);
        }
        else    /* 找不到資料則顯示錯誤 */
            printf(" Student %s not found\n", delName);
    }
}

void modifyFunction(void)
{
    int count = 0;
    char nTemp[20], sTemp[4];
    
    if(head->next == head) printf(" No student record\n");
    else{
        printf("\n Modify student name: ");
        gets(nTemp);
        prev = head;
        currentN=head->next;
        while ((currentN != head) && (strcmp(currentN->name , nTemp)!=0)) {
            prev = currentN;
            currentN = currentN->next;
        }
        if (currentN != head){
            printf(" **************************\n");
            printf("  Student name : %s\n", currentN->name);
            printf("  Student score: %d\n", currentN->score);
            printf(" **************************\n");
            printf(" Please enter new score: ");
            gets(sTemp);
            prev->next = currentN->next;
            free(currentN);
            ptr = (struct student *) malloc(sizeof(struct student));
            strcpy(ptr->name, nTemp);
            ptr->score = atoi(sTemp);
            ptr->next=NULL;
            prev = head;
            currentN = head->next;
            if (currentN != head) {
                while ((currentN != head) && (currentN->score > ptr->score)){
                    prev = currentN;
                    currentN = currentN->next;
                }
            }
            ptr->next = currentN;
            prev->next = ptr;
            printf(" Student %s has been modified\n",nTemp);
        }
        else     /* 找不到資料則顯示錯誤 */
            printf(" Student %s not found\n", nTemp);
    }
}

void displayFunction(void)
{
    int count = 0;
    
    if(head->next == head ) printf(" No student record\n");
    else{
        printf("\n  NAME                SCORE\n");
        printf(" ---------------------------\n");
        currentN=head->next;
        do{
            printf("  %-20s %3d\n", currentN->name, currentN->score);
            count++;
            currentN=currentN->next;
            if(count % 20 == 0) getchar();
        }  while(currentN != head);
        printf(" ---------------------------\n");
        printf(" Total %d record(s) found\n", count);
    }
}