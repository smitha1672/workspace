/* File name: BinSearchTree.c */ 
/* Version 4.0, June, 2017 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

/* 定義student結構 */
struct student {
	char name[20];  /* 學生姓名 */
	int score;  /* 學生成績 */ 	struct student *llink;  /* 左子鏈結 */
	struct student *rlink;  /* 右子鏈結 */
};

void insertFunction(void);    /* 新增函數 */
void deleteFunction(void);    /* 刪除函數 */
void modifyFunction(void);    /* 修改函數 */
void showFunction(void);      /* 輸出函數 */
void access(char [], int);  /* 將資料加入二元搜尋樹 */
void removing(char []);  /* 將資料從二元搜尋樹中移除 */
struct student *replace(struct student *);  /* 尋找替代節點 */
void connect(struct student *, char);  /* 調整鏈結 */
void inorder(struct student *);  /* 資料以中序法輸出 */
void preorder(struct student *, FILE *);  /* 資料以前序法寫入檔案 */
struct student *search(char []);  /* 搜尋節點 */
struct student *searchReR(struct student *);  /* 搜尋右子樹替代節點 */
struct student *searchReL(struct student *);  /* 搜尋左子樹替代節點 */
struct student *searchP(struct student *);  /* 搜尋父節點 */

struct student *root, *ptr;

int main()
{
	char option;
	while(1){
		puts("");
		puts("********************");
		puts("     <1> insert");
		puts("     <2> delete");
		puts("     <3> modify");
		puts("     <4> show");
		puts("     <5> quit");
		puts("********************");
		printf("Enter your choice: ");
		option = getchar();
		while (getchar()!='\n') continue;
		printf("\n\n");
		switch(option){
			case '1':
				insertFunction();
				break;
			case '2':
				deleteFunction();
				break;
			case '3':
				modifyFunction();
				break;
			case '4':
				showFunction();
				break;
			case '5':
				exit(0);
			default :
				puts("Wrong option!");
		}
	}
	printf("\n");
	return 0;
}

/* 新增函數，新增一筆新的資料 */
void insertFunction(void)
{
	char name[20], temp[4];
	int score;
	puts("=====INSERT DATA=====");
	printf("Enter student name: ");
	gets(name);
	printf("Enter student score: ");
	gets(temp);
	score = atoi(temp);
	access(name, score);
}

/* 刪除函數，將資料從二元搜尋樹中刪除 */
void deleteFunction(void)
{
	char name[20];
	if(root == NULL){
		puts("No student record!");
		return;
	}
	puts("=====DELETE DATA=====");
	printf("Enter student name: ");
	gets(name); 
	removing(name);
}

/* 修改資料，修改學生成績 */
void modifyFunction(void)
{
	struct student *node;
	char name[20], temp[4];
	if(root == NULL){  /* 判斷根節點是否為NULL */
		puts("No student record!");
		return;
	}
	puts("=====MODIFY DATA===== ");
	printf("Enter student name: ");
	gets(name);
	if((node = search(name)) == NULL)
		printf("Student %s not found!\n", name);
	else{
		/* 列出原資料狀況 */
		printf("Original student name: %s\n", node->name);
		printf("Original student score: %d\n", node->score);
		printf("Enter new score: ");
		gets(temp);
		node->score = atoi(temp);
		printf("Student %s has been modified\n", name);
	}
}

 /* 輸出函數，將資料輸出至螢幕 */
void showFunction(void)
{
	if(root == NULL){  /* 判斷根節點是否為NULL */
		puts("No student record!");
		return;
	}
	puts("=====SHOW DATA=====");
	inorder(root);  /* 以中序法輸出資料 */
}

/* 處理二元搜尋樹，將新增資料加入至二元搜尋樹中 */
void access(char name[], int score)
{
	struct student *node, *prev;
	if(search(name) != NULL){  /* 資料已存在則顯示錯誤 */
		printf("Student %s has existed!\n", name);
		return;
	}
	ptr = (struct student *) malloc(sizeof(struct student));
	strcpy(ptr->name, name);
	ptr->score = score;
	ptr->llink = ptr->rlink = NULL;
	if(root == NULL)  /* 當根節點為NULL的狀況 */
		root = ptr;
	else{             /* 當根節點不為NULL的狀況 */
		node = root;
		while(node != NULL){  /* 搜尋資料插入點 */
			prev = node;
			if(strcmp(ptr->name, node->name) < 0)
				node = node->llink;
			else
				node = node->rlink;
		}
		if(strcmp(ptr->name, prev->name) < 0)
			prev->llink = ptr;
		else
			prev->rlink = ptr;
	}
	printf("Student %s has been inserted!\n", name);
}

/* 將資料從二元搜尋樹中移除 */
void removing(char name[])
{
	struct student *delNode;
	if((delNode = search(name)) == NULL){  /* 找不到資料則顯示錯誤 */
		printf("Student %s not found!\n", name);
		return;
	}
	/* 節點不為樹葉節點的狀況 */
	if(delNode->llink != NULL || delNode->rlink != NULL)
		delNode = replace(delNode);
	else  /* 節點為樹葉節點的狀況 */
		if(delNode == root)
			root = NULL;
		else
			connect(delNode, 'n');
	free(delNode);  /* 釋放記憶體 */
	printf("Student %s has been deleted!\n", name);
}

/* 尋找刪除非樹葉節點的替代節點 */
struct student *replace(struct student *node)
{
	struct student *reNode;
	/* 當右子樹找不到替代節點，會搜尋左子樹是否存在替代節點 */
	if((reNode = searchReR(node->rlink)) == NULL)
		reNode = searchReL(node->llink);
	if(reNode->rlink != NULL)  /* 當替代節點有右子樹存在的狀況 */
		connect(reNode, 'r');
	else
		if(reNode->llink != NULL)  /* 當替代節點有左子樹存在的狀況 */
			connect(reNode, 'l');
		else  /* 當替代節點為樹葉節點的狀況 */
			connect(reNode, 'n');
	strcpy(node->name, reNode->name);
	node->score = reNode->score;
	return reNode;
}

/* 調整二元搜尋樹的鏈結，link為r表示處理右鏈結，為l表處理左鏈結，
   為m則將鏈結指向NULL */
void connect(struct student *node, char link)
{
	struct student *parent;
	parent = searchP(node);  /* 搜尋父節點 */
	/* 節點為父節點左子樹的狀況 */
	if(strcmp(node->name, parent->name) < 0)
		if(link == 'r')  /* link為r */
			parent->llink = node->rlink;
		else
			if(link == 'l')  /* link為l */
				parent->llink = node->llink;
			else  /* link為m */
				parent->llink = NULL;
	else  /* 節點為父節點右子樹的狀況 */
		if(link == 'r')  /* link為r */
			parent->rlink = node->rlink;
		else
			if(link == 'l')  /* link為l */
				parent->rlink = node->llink;
			else  /* link為m */
	parent->rlink = NULL;
}

/* 以中序法輸出資料，採遞迴方式 */
void inorder(struct student *node)
{
	if(node != NULL){
		inorder(node->llink);
		printf("%-10s %d\n", node->name, node->score);
		inorder(node->rlink);
	}
}

/* 以前序法將資料寫入檔案，採遞迴方式 */
void preorder(struct student *node, FILE *fptr)
{
	if(node != NULL){
		fprintf(fptr, "%s %d\n", node->name, node->score);
		preorder(node->llink, fptr);
		preorder(node->rlink, fptr);
	}
}

/* 搜尋target所在節點 */
struct student *search(char target[])
{
	struct student *node;
	node = root;
	while(node != NULL){
		if(strcmp(target, node->name) == 0)
			return node;
		else
			/* target小於目前節點，往左搜尋 */
			if(strcmp(target, node->name) < 0)
				node = node->llink;
			else  /* target大於目前節點，往右搜尋 */
				node = node->rlink;
	}
	return node;
}

/* 搜尋右子樹替代節點 */
struct student *searchReR(struct student *node)
{
	struct student *reNode;
	reNode = node;
	while(reNode != NULL && reNode->llink != NULL)
		reNode = reNode->llink;
	return reNode;
}

/* 搜尋左子樹替代節點 */
struct student *searchReL(struct student *node)
{
	struct student *reNode;
	reNode = node;
	while(reNode != NULL && reNode->rlink != NULL)
		reNode = reNode->rlink;
	return reNode;
}

/* 搜尋node的父節點 */
struct student *searchP(struct student *node)
{
	struct student *parent;
	parent = root;
	while(parent != NULL){
		if(strcmp(node->name, parent->name) < 0)
			if(strcmp(node->name, parent->llink->name) == 0)
				return parent;
			else
				parent = parent->llink;
		else
			if(strcmp(node->name, parent->rlink->name) == 0)
				return parent;
			else
				parent = parent->rlink;
	}
	return NULL;
}