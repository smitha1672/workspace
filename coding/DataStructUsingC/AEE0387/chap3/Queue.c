/* File name: Queue.c*/
/* Version 4.0, June, 2017 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 20
void enqueueFunction(void);   /* 新增函數 */
void dequeueFunction(void);   /* 刪除函數 */
void listFunction(void);   /* 輸出函數 */

char item[MAX][20];
int front = 0, rear = -1;

int main()
{
    char option;
    while(1){
        printf("\n *****************************\n");
        printf("       <1> insert (enqueue)\n");
        printf("       <2> delete (dequeue)\n");
        printf("       <3> list\n");
        printf("       <4> quit\n");
        printf(" *****************************\n");
        printf(" Please enter your choice...");
        option = getchar();
        while (getchar()!='\n') continue;
        switch(option)	{
            case '1':
                enqueueFunction();
                break;
            case '2':
                dequeueFunction();
                break;
            case '3':
                listFunction();
                break;
            case '4':
                exit(0);
        }
    }
}

void enqueueFunction(void)
{
    if(rear >= MAX-1)   /* 當佇列已滿，則顯示錯誤 */
        printf("\n\nQueue is full !\n");
    else{
        rear++;
        printf("\n\n Please enter item to insert: ");
        gets(item[rear]);
    }
}

void dequeueFunction(void)
{
    if(front > rear)   /* 當資料沒有資料存在，則顯示錯誤 */
        printf("\n\n No item, queue is empty !\n");
    else{
        printf("\n\n Item %s deleted\n", item[front]);
        front++;
    }
}

void listFunction(void)
{
    int count = 0, i;
    if(front > rear)
        printf("\n\n No item, queue is empty\n");
    else{
        printf("\n\n  ITEM\n");
        printf(" ------------------\n");
        for(i = front; i <= rear; i++){
            printf("  %-20s\n", item[i]);
            count++;
            if(count % 20 == 0) getchar();
        }
        printf(" ------------------\n");
        printf("  Total item: %d\n", count);
    }
}
