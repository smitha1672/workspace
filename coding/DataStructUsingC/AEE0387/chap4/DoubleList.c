/* File name: DoubleList.c */
/* Version 4.0, June, 2017 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void initFunction(void);     /* 初始化串列，建立一空節點為HEAD */
void insertFunction(void);   /* 插入函數 */
void sortFunction(void);     /* 排序函數 */
void deleteFunction(void);   /* 刪除函數 */
void displayFunction(void);  /* 輸出函數 */
void modifyFunction(void);   /* 修改函數 */

struct student {
	char name[20];          /* 姓名 */
	int score;               /* 分數 */
	struct student *llink;  /* 節點左鏈結 */
	struct student *rlink;  /* 節點右鏈結 */
};

struct student *ptr, *head, *tail, *currentN, *prev;

int main()
{
	char option1;

	initFunction();
	while(1){
		printf("\n ****************************************\n");
		printf("              1.insert\n");
		printf("              2.delete\n");
		printf("              3.display\n");
		printf("              4.modify\n");
		printf("              5.quit\n");
		printf(" ****************************************\n");
		printf("   Please enter your choice (1-5)...");
		option1 = getchar();
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

void initFunction(void)  /* 設一HEAD，將左右鏈結皆指向本身 */
{
	ptr = (struct student *) malloc(sizeof(struct student));
	strcpy(ptr->name, "0");
	ptr->llink = ptr;
	ptr->rlink = ptr;
	head = ptr;
	tail = ptr;
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
	prev = head;
	currentN = head->rlink;
	while((currentN != head) && (currentN->score >= ptr->score)) {
		prev = currentN;
		currentN = currentN->rlink;
	}
	ptr->rlink = currentN;
	ptr->llink = prev;
	prev->rlink = ptr;
	currentN->llink = ptr;
}

void deleteFunction(void)
{
	char delName[20];
	int count = 0;

	if(head->rlink == head) printf(" No student record\n");
	else
	{
		printf("\n Delete student name: ");
		gets(delName);
		prev = head;
		currentN = head->rlink;
		while ((currentN != head) && (strcmp(currentN->name , delName)!=0))
 {
			prev = currentN;
			currentN = currentN->rlink;
		}
		if (currentN != head) {
			prev->rlink = currentN->rlink;
			currentN->rlink->llink = prev;
			free(currentN);
			printf(" Student %s has been deleted\n",delName);
		}
		else
			printf(" Student %s not found\n",delName);
	}
}

void modifyFunction(void)
{
	int count = 0;
	char nTemp[20], sTemp[4];

	if(head->rlink == head) printf(" No student recond\n"); /* 無資料顯示錯誤 */
	else
	{
		printf("\n Modify student name: ");
		gets(nTemp);
		prev=head;
		currentN=head->rlink;
		while ((currentN != head) && (strcmp(currentN->name , nTemp)!=0)){
			prev = currentN;
			currentN = currentN->rlink;
		}
		if (currentN != head)  {
			printf(" **************************\n");
			printf("  Student name : %s\n",currentN->name);
			printf("  Student score: %d\n",currentN->score);
			printf(" **************************\n");
			printf(" Please enter new score: ");
			gets(sTemp);
			prev->rlink = currentN->rlink;
			currentN->rlink->llink = prev;
			free(currentN);
			//重新加入
			ptr = (struct student *) malloc(sizeof(struct student));
			strcpy(ptr->name, nTemp);
			ptr->score = atoi(sTemp);
			ptr->rlink = head;
			prev = head;
			currentN = head->rlink;
			while ((currentN != head) && (currentN->score > ptr->score)) {
				prev = currentN;
				currentN = currentN->rlink;
			}
	        ptr->rlink = currentN;
	        ptr->llink = prev;
	        prev->rlink = ptr;
	        currentN->llink = ptr;
			printf("%s student record(s) modified\n", nTemp);
		}
		else     // 找不到資料則顯示錯誤
			printf(" Student %s not found\n",nTemp);
	}
}

void displayFunction(void)
{
	int count = 0;

	if(head->rlink == head) printf(" No student record\n");
	else
	{
		printf("\n  NAME                SCORE\n");
		printf(" ---------------------------\n");
		currentN = head->rlink;
		while(currentN != head)
		{
			printf("  %-20s %3d\n", currentN->name, currentN->score);
			count++;
			currentN = currentN->rlink;
			if(count % 20 == 0) getchar(); /* 每次印出20筆資料 */
		}
		printf(" ---------------------------\n");
		printf(" Total %d record(s) found\n", count);
	}
}