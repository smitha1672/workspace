/* File name: Avltree.c */
/* Version 4.0, June, 2017 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct student {
	char name[20];  /* 姓名 */
	int score;  /* 分數 */
	int bf;  /* 節點BF值 */
	struct student *llink, *rlink;  /* 節點子鏈結 */
};

void insertFunction(void);  /* 插入函數 */
void deleteFunction(void);  /* 刪除函數 */
void modifyFunction(void);  /* 修改函數 */
void listFunction(void);    /* 輸出函數 */
void sortFunction(char[], char[]);      /* 插入檔案後排序 */
void inorder(struct student *);   /* 輸出使用中序追蹤 */
void preorder(FILE *, struct student *);  /* 存檔使用前序追蹤 */
void bfCount(struct student *);  /* 計算節點BF值 */
int heightCount(struct student *);   /* 計算節點高度 */
void pivotFind(void);   /* 找出pivot所在節點 */
void ptrFind(struct student *);  /* 於刪除時找出PTR所在位置 */
int typeFind(void);     /* 找出改善方法 */
void typeLL(void);      /* 使用LL型態 */
void typeRR(void);      /* 使用RR型態 */
void typeLR(void);      /* 使用LR型態 */
void typeRL(void);      /* 使用RL型態 */
void anykeyFunction(void);

struct student *ptr, *root, *current, *prev, *pivot, *pivotPrev;

int main()
{
	char option;
	while(1){
		printf("\n *****************************\n");
		printf("         <1> insert\n");
		printf("         <2> delete\n");
		printf("         <3> modify\n");
		printf("         <4> list\n");
		printf("         <5> exit\n");
		printf(" *****************************\n");
		printf("  Please input your choice: ");
		option = getchar();
		while (getchar()!='\n') continue;
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
				listFunction();
				break;
			case '5':
				printf("\n");
				return 0;
		}
	}
  }

void insertFunction(void)
{
	char nameT[20], scoreT[4];

	printf("\n Please enter student name: ");
	gets(nameT);
	printf(" Please enter student score: ");
	gets(scoreT);
	sortFunction(nameT, scoreT);   /* 呼叫SORTFunction函數作排序及平衡 */
}

void sortFunction(char nameT[], char scoreT[])
{
	int op;
	current = root;
	while((current != NULL) && (strcmp(nameT, current->name) != 0)){
		if(strcmp(nameT, current->name) < 0){  /* 插入資料小於目前位置，則往左移 */
			prev = current;
			current = current->llink;
		}
		else{   /* 若大於目前位置，則往右移 */
			prev = current;
			current = current->rlink;
		}
	}
	/* 找到插入位置，無重覆資料存在 */
	if(current == NULL || strcmp(nameT, current->name) != 0){
		ptr = (struct student *) malloc(sizeof(struct student));
		strcpy(ptr->name, nameT);
		ptr->score = atoi(scoreT);
		ptr->llink = NULL;
		ptr->rlink = NULL;
		if(root == NULL) root = ptr;   /* ROOT不存在，則將ROOT指向插入資料 */
			if(prev != NULL)
				if(strcmp(ptr->name, prev->name) < 0) prev->llink = ptr;
				else prev->rlink = ptr;
		bfCount(root);
		pivotFind();
		if(pivot != NULL){   /* PIVOT存在，則須改善為AVL-TREE */
			op = typeFind();
			switch(op){
				case 11:
					typeLL();
					break;
				case 22:
					typeRR();
					break;
				case 12:
					typeLR();
					break;
				case 21:
					typeRL();
					break;
			}
		}
		bfCount(root);  /* 重新計算每個節點的BF值 */
	}
	else{ /* 欲插入資料KEY已存在，則顯示錯誤 */
		printf(" Student %s has existed\n", nameT);
	}
}

void deleteFunction(void)
{
	struct student *clear;
	char nameT[20];
	int op;

	/* 若根不存在，則顯示錯誤 */
	if(root == NULL)
		printf(" No student record\n");
	else{
		printf("\n Please enter student name to delete: ");
		gets(nameT);
		current = root;
		while(current != NULL && strcmp(nameT, current->name) != 0){
			/* 若刪除資料鍵值小於目前所在資料，則往左子樹 */
			if(strcmp(nameT, current->name) < 0){
				prev = current;
				current = current->llink;
			}
			/* 否則則往右子樹 */
			else{
				prev = current;
				current = current->rlink;
			}
		}
 
		// 找不到刪除資料，則顯示錯誤
		if (current == NULL ) {
			printf(" Not found student %s \n\n", nameT);
		      return;
             }

		/* 找到欲刪除資料的狀況 */
		if(strcmp(nameT, current->name) == 0){
			/* 當欲刪除資料底下無左右子樹存在的狀況 */
			if(current->llink == NULL && current->rlink == NULL){
				clear = current;
				if(strcmp(nameT, root->name) == 0)  /* 欲刪除資料為根 */
					root = NULL;
				else{	/* 若不為根，則判斷其為左子樹或右子樹 */
					if(strcmp(nameT, prev->name) < 0)
						prev->llink = NULL;
					else
						prev->rlink = NULL;
					ptrFind(prev);    /* 從PREV的位置開始往下找PTR */
				}
				free(clear);
			}
			else{
				/* 以左子樹最大點代替刪除資料 */
				if(current->llink != NULL){
					clear = current->llink;
					while(clear->rlink != NULL){
						prev = clear;
						clear = clear->rlink;
					}
					strcpy(current->name, clear->name);
					current->score = clear->score;
					if(current->llink == clear)
						current->llink = clear->llink;
					else
						prev->rlink = clear->llink;
				}
				/* 以右子樹最小點代替刪除資料 */
				else{
					clear = current->rlink;
					while(clear->llink != NULL){
						prev = clear;
						clear = clear->llink;
					}
					strcpy(current->name, clear->name);
					current->score = clear->score;
					if(current->rlink == clear)
						current->rlink = clear->rlink;
					else
						prev->llink = clear->rlink;
				}
 				free(clear);
			}

			bfCount(root);
			if(root != NULL){     /* 若根不存在，則無需作平衡改善 */
				pivotFind();      /* 尋找PIVOT所在節點 */
				if(pivot != NULL){
					op = typeFind();
					switch(op){
						case 11:
							typeLL();
							break;
						case 22:
							typeRR();
							break;
						case 12:
							typeLR();
							break;
						case 21:
							typeRL();
							break;
					}
				}
				bfCount(root);
			}
			printf(" Student %s has been deleted\n\n", nameT);
		}
 
	}
}

void modifyFunction(void)
{
	char nameT[20], scoreT[4];

	printf("\n Please enter student name to update: ");
	gets(nameT);
	current = root;
	/* 尋找欲更改資料所在節點 */
	while((current != NULL) && (strcmp(nameT, current->name) != 0)){
		if(strcmp(nameT, current->name) < 0) current = current->llink;
		else current = current->rlink;
	}
	/* 若找到欲更改資料，則列出原資料，並要求輸入新的資料 */
	if(current != NULL){
		printf(" ****************************\n");
		printf("  Student name : %s\n", current->name);
		printf("  Student score: %d\n", current->score);
		printf(" ****************************\n");
		printf(" Please enter new score: ");
		gets(scoreT);
		current->score = atoi(scoreT);
		printf(" Data update successfully\n");
	}
	/* 沒有找到資料則顯示錯誤 */
	else
		printf(" Student %s not found\n", nameT);
}


void listFunction(void)
{

	if(root == NULL) printf(" No student record\n");
	else{
		printf("\n *****************************\n");
		printf("   Name                Score\n");
		printf("  ---------------------------\n");
		inorder(root);   /* 使用中序法輸出資料 */
		printf(" *****************************\n");
	}
}

void inorder(struct student *trees)  /* 中序使用遞迴 */
{
	if(trees != NULL){
		inorder(trees->llink);
		printf("   %-20s %3d\n", trees->name, trees->score);
		inorder(trees->rlink);
	}
}

void preorder(FILE *fptr, struct student *trees) /* 前序採遞迴法 */
{
	if(trees != NULL){
		fprintf(fptr, "%s %d\n", trees->name, trees->score);
		preorder(fptr, trees->llink);
		preorder(fptr, trees->rlink);
	}
}

void bfCount(struct student *trees)  /* 計算BF值，使用後序法逐一計算 */
{
	if(trees != NULL){
		bfCount(trees->llink);
		bfCount(trees->rlink);
		/* BF值計算方式為左子樹高減去右子樹高 */
	      trees->bf = heightCount(trees->llink) - heightCount(trees->rlink);
	}
}

int heightCount(struct student *trees)
{
	if(trees == NULL) return 0;
	else
		if(trees->llink == NULL && trees->rlink == NULL) return 1;
	else return 1 + (heightCount(trees->llink) > heightCount(trees->rlink) ?
             heightCount(trees->llink) : heightCount(trees->rlink));
}

void pivotFind(void)
{
	current = root;
	pivot = NULL;
	while(current != ptr){
		/* 當BF值的絕對值大於等於1，則將PIVOT指向此節點 */
		if(current->bf < -1 || current->bf > 1){
			pivot = current;
			if(pivot != root) pivotPrev = prev;
		}
		if(strcmp(ptr->name, current->name) < 0){
			prev = current;
			current = current->llink;
		}
		else{
			prev = current;
			current = current->rlink;
		}
	}
}

/* 因刪除資料時，並不存在判斷PIVOT所需的PTR指標，利用此函數找出 */
void ptrFind(struct student *temp)
{
	struct student *ltemp, *rtemp;
	int lcount = 0, rcount = 0;
	ltemp = rtemp = temp;
	while(ltemp->llink != NULL && ltemp->rlink != NULL){
		while(ltemp->llink != NULL){
			ltemp = ltemp->llink;
			lcount++;
		}
		while(ltemp->rlink != NULL){
			ltemp = ltemp->rlink;
			lcount++;
		}
	}
	while(rtemp->rlink != NULL && rtemp->llink != NULL){
		while(rtemp->rlink != NULL){
			rtemp = rtemp->rlink;
			rcount++;
		}
		while(rtemp->llink != NULL){
			rtemp = rtemp->llink;
			rcount++;
		}
	}
	/* 距離TEMP最遠的節點才為PTR可能的所在位置 */
	ptr = lcount > rcount ? ltemp : rtemp;
}

int typeFind(void)
{
	int i, opR = 0;
	current = pivot;
	for(i = 0; i < 2; i++){
		if(strcmp(ptr->name, current->name) < 0){
			current = current->llink;
			if(opR == 0) opR+=10;
			else opR++;
		}
		else{
			current = current->rlink;
			if(opR == 0) opR+=20;
			else opR+=2;
		}
	}
	/* 傳回值11、22、12、21分別代表LL、RR、LR、RL型態 */
	return opR;
}

void typeLL(void)  /* LL型態 */
{
	struct student *pivotNext, *temp;
	pivotNext = pivot->llink;
	temp = pivotNext->rlink;
	pivotNext->rlink = pivot;
	pivot->llink = temp;
	if(pivot == root) root = pivotNext;
	else
		if(pivotPrev->llink == pivot)
			pivotPrev->llink = pivotNext;
		else
			pivotPrev->rlink = pivotNext;
}

void typeRR(void)  /* RR型態 */
{
	struct student *pivotNext, *temp;
	pivotNext = pivot->rlink;
	temp = pivotNext->llink;
	pivotNext->llink = pivot;
	pivot->rlink = temp;
	if(pivot == root) root = pivotNext;
	else
		if(pivotPrev->llink == pivot)
			pivotPrev->llink = pivotNext;
		else
			pivotPrev->rlink = pivotNext;
}


void typeLR(void)  /* LR型態 */
{
	struct student *pivotNext, *temp;
	pivotNext = pivot->llink;
	temp = pivotNext->rlink;
	pivot->llink = temp->rlink;
	pivotNext->rlink = temp->llink;
	temp->llink = pivotNext;
	temp->rlink = pivot;
	if(pivot == root) root = temp;
	else
		if(pivotPrev->llink == pivot)
			pivotPrev->llink = temp;
		else
			pivotPrev->rlink = temp;
}

void typeRL(void)  /* RL型態 */
{
	struct student *pivotNext, *temp;
	pivotNext = pivot->rlink;
	temp = pivotNext->llink;
	pivot->rlink = temp->llink;
	pivotNext->llink = temp->rlink;
	temp->rlink = pivotNext;
	temp->llink = pivot;
	if(pivot == root) root = temp;
	else
		if(pivotPrev->llink == pivot)
			pivotPrev->llink = temp;
		else
			pivotPrev->rlink = temp;
}