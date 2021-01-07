/* File name: SortBi.c */
/* Version 4.0, June, 2017 */

#include <stdio.h>
#include <stdlib.h>

struct data {
		int num;
		struct data *llink, *rlink;
} *root, *tree, *leaf;

void find(int, struct data *);
void output(struct data *);

int main()
{
	int data[10] = {75, 23, 98, 44, 57, 12, 29, 64, 38, 82};
	int i;

	printf("\n<< Binary tree sort >>\n");
	printf("\nNumber : ");
	for(i = 0; i < 10; i++)
		printf("%d  ", data[i]);
	puts("");
	for(i = 0; i < 60; i++) printf("-");
	root = (struct data *) malloc(sizeof(struct data));
	root->num = data[0];     /* 建樹根 */
	root->llink = NULL;
	root->rlink = NULL;
	printf("\nSorting... : ");
	output(root);
	leaf = (struct data *) malloc(sizeof(struct data));
	for(i = 1; i < 10; i++){  /* 建樹枝 */
		leaf->num = data[i];
		leaf->llink = NULL;
		leaf->rlink = NULL;
		find(leaf->num, root);
		if(leaf->num > tree->num)  /* 若比父節點大，則放右子樹 */
			tree->rlink = leaf;
		else                       /* 否則放在左子樹 */
			tree->llink = leaf;
		printf("\nSorting... : ");
		output(root);
		leaf = (struct data *) malloc(sizeof(struct data));
	}
	puts("");
	for(i = 0; i < 60; i++) printf("-");
	printf("\nSorted data: ");
	output(root);
	printf("\n");
	return 0;
}

/* 尋找新節點存放的位置 */
void find(int input, struct data *papa)
{
	if((input > papa->num) && (papa->rlink != NULL))
		find(input, papa->rlink);
	else if((input < papa->num) && (papa->llink != NULL))
		find(input, papa->llink);
	else
		tree = papa;
}

/* 印出資料 */
void output(struct data *node)   /* 用中序追蹤將資料印出 */
{
	if(node != NULL){
		output(node->llink);
		printf("%d  ", node->num);
		output(node->rlink);
	}
}