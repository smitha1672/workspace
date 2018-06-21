/* File name: Mwaytree.c */
/* Version 4.0, June, 2017 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX 3    /* 設定M-WAY TREE的最大節點數 */
typedef struct mwayTree {           /* 定義資料欄位 */
		char id;                      /* 輸出時識別節點 */
		int n;                        /* 節點內的鍵值數 */
		int key[MAX];                /* 節點鍵值 */
		struct mwayTree *link[MAX];  /* 節點子鏈節 */
} NodeType;

void insertFunction(void);    /* 插入函數 */
void deleteFunction(void);    /* 刪除函數 */
void displayFunction(void);   /* 輸出函數 */
void create(int);       /* 加入資料後調整為M-WAY TREE */
void removes(NodeType *, int);  /* 移除資料後調整為M-WAY TREE */
void initial(void);     /* 節點初始化 */
int searchNum(int);    /* 搜尋鍵值所在節點位置 */
NodeType *searchNode(int);  /* 搜尋鍵值所在節點 */
void moveright(int, int);     /* 節點內資料往右移 */
void moveleft(int);           /* 節點內資料往左移 */
NodeType *findNext(NodeType *);  /* 尋找後繼節點 */
NodeType *findPrev(NodeType *);  /* 尋找前行節點 */
void preorderId(NodeType *);    /* 給予每個節點識別編號 */
void preorderNum(NodeType *);   /* 輸出節點 */
void preorderSave(NodeType *);  /* 將資料輸出至檔案 */
NodeType *ptr, *root, *node, *prev, *parent, *replace;
char idSeq;

int main(void)
{
	char option;
	do{
		printf("\n ***************************\n");
		printf("        <1> insert\n");
		printf("        <2> delete\n");
		printf("        <3> display\n");
		printf("        <4> quit\n");
		printf(" ***************************\n");
		printf(" Please enter your choice: ");
		option = getchar();
		while (getchar()!='\n') continue;
		printf("\n");
		switch(option){
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
				break;
			default : printf("\n Option error!!\n");
		}
	} while(option != '4');
	return 0;
}

/* 插入函數--新增一筆資料 */
void insertFunction(void)
{
	int addNum;
	printf("\n Please enter insert number: ");
	scanf("%d", &addNum);
	while (getchar()!='\n') continue;
	create(addNum);
	printf("Number %d has been inserted!\n", addNum);
}

/* 刪除函數--刪除一筆資料 */
void deleteFunction(void)
{
	int delNum, ans;
	if(root == NULL)  /* 當樹根為NULL，顯示錯誤訊息 */
		printf("\n No data found!!\n");
	else{
		printf("\n Please enter delete number: ");
		scanf("%d", &delNum);
		while (getchar()!='\n') continue;
		ans = searchNum(delNum);  /* 搜尋資料是否存在 */
		if(ans == 0)  /* 當資料不存在，顯示錯誤訊息 */
			printf(" Number %d not found!!\n", delNum);
		else{
			removes(node, ans);
			printf(" Number %d has been deleted!!\n", delNum);
		}
	}
}

/* 輸出函數--將M-WAY TREE內的所有資料輸出 */
void displayFunction(void)
{
	if(root == NULL)  /* 當樹根為NULL，顯示錯誤訊息 */
		printf("\n No data found!!\n");
	else{
		idSeq = 'a';  /* 節點編號由a開始 */
		preorderId(root);  /* 給予每個節點編點 */
		printf("\n =========================================\n");
		preorderNum(root); /* 輸出節點資料 */
		printf(" ===========================================\n");
	}
}

/* 將資料加入，並調整為M-WAY TREE，NUM為新增之資料鍵值 */
void create(int num)
{
	int ans, i;
	if(root == NULL){  /* 樹根為NULL的狀況 */
		initial();
		ptr->key[1] = num;
		ptr->n++;
		root = ptr;
	}
	else{
		ans = searchNum(num);  /* 搜尋資料是否已存在 */
		if(ans != 0)  /* 資料存在，則顯示錯誤訊息 */
			printf(" Number %d has existed!!\n", num);
		else{
			node = searchNode(num);  /* 找尋插入點 */
			if(node != NULL){  /* 插入點還有空間存放資料的狀況 */
				for(i = 1; i < MAX-1; i++)
					if(num < node->key[i]) break;
				moveright(i, num);
			}
			else{  /* 新增加一個節點加入資料的狀況 */
				initial();
				ptr->key[1] = num;
				ptr->n++;
				for(i = 1; i < MAX; i++)
					if(num < prev->key[i]) break;
				prev->link[i-1] = ptr;
			}
		}
	}
}

/* 將資料移除，並調整為M-WAY TREE，NODETEMP為刪除資料所在節點，
   LOCATION為資料在節點中的位置 */
void removes(NodeType *nodeTemp, int location)
{
	int i;
	node = nodeTemp;
	replace = findNext(node->link[location]);/*找尋替代之後繼節點*/
	if(replace == NULL){  /* 沒有後繼節點的狀況 */
		replace = findPrev(node->link[location-1]); 
/* 找尋替代之前行節點 */
		if(replace == NULL){  /* 沒有前行節點的狀況 */
			moveleft(location);
			replace = node;
			if(node->n == 0){  /* 刪除資料後，節點內資料為0的處理 */
				if(node == root)  /* 當節點為根的狀況 */
					root = NULL;
				else  /* 節點不是根，則調整鏈結 */
					for(i = 0; i <= parent->n; i++)
						if(node == parent->link[i]){
							parent->link[i] = NULL;
							break;
						}
				free(replace);
			}
		}
		else{  /* 有前行節點的狀況 */
			/* 以前行節點的資料代替刪除資料 */
			node->key[location] = replace->key[replace->n];
			parent = prev;
			removes(replace, replace->n);  /* 移除替代資料 */
		}
	}
	else{  /* 有後繼節點的狀況 */
		/* 以後繼節點的資料代替刪除資料 */
		node->key[location] = replace->key[1];
		parent = prev;
		removes(replace, 1);  /* 移除替代資料 */
	}
}

/* 初始化節點--新增一個節點，將其所有鏈結指向NULL，設其節點數為0 */
void initial(void)
{
	int i;
	ptr = (NodeType *) malloc(sizeof(NodeType));
	for(i = 0; i < MAX; i++)
		ptr->link[i] = NULL;
	ptr->n = 0;
}

/* 搜尋節點位置--搜尋NUM，存在則回傳NUM在節點中的位置，不存在則回傳0 */
int searchNum(int num)
{
	int done, i;
	node = root;
	while(node != NULL){
		parent = prev;
		prev = node;
		for(i = 1, done = 0; i <= node->n; i++){
			if(num == node->key[i])
				return i;   /* 找到NUM，回傳其在節點中的位置 */
			if(num < node->key[i]){
				node = node->link[i-1];
				done = 1;
				break;
			}
		}
		if(done == 0)
			node = node->link[i-1];
	}
	return 0;   /* 沒有找到則回傳0 */
}

/* 搜尋節點--尋找插入NUM的節點，並回傳插入節點 */
NodeType *searchNode(int num)
{
	int i, done;
	NodeType *nodeTemp; 		nodeTemp = root;
	while(nodeTemp != NULL){
		if(nodeTemp->n < MAX-1)
			return nodeTemp;  /* 找到有多餘空間存放NUM，則回傳此節點 */
		else{
		for(i = 1, done = 0; i < MAX; i++){
				if(nodeTemp->n < i)
					break;
				if(num < nodeTemp->key[i]){
					nodeTemp = nodeTemp->link[i-1];
					done = 1;
					break;
				}
			}
			if(done == 0)
				nodeTemp = nodeTemp->link[i-1];
		}
	}
	return nodeTemp;  /* 若沒有找到有多餘空間存放NUM的節點，回傳NULL */
}

/* 將節點內資料右移--將節點資料右移至INDEX位置，並將NUM插入 */
void moveright(int index, int num)
{
	int i;
	for(i = node->n+1; i > index; i--){  /* 資料右移至INDEX處 */
		node->key[i] = node->key[i-1];
		node->link[i] = node->link[i-1];
	}
	node->key[i] = num;  /* 插入NUM */
	/* 調整NUM左右鏈結 */
		if(node->link[i-1] != NULL && node->link[i-1]->key[0] > num){
		node->link[i] = node->link[i-1];
		node->link[i-1] = NULL;
	}
	node->n++;
}

/* 將節點內資料左移--將節點資料從INDEX位置左移 */
void moveleft(int index)
{
	int i;
	for(i = index; i < node->n; i++){  /* 節點資料左移 */
		node->key[i] = node->key[i+1];
		node->link[i] = node->link[i+1];
	}
	node->n--;
}
 
/* 尋找後繼節點--尋找NODETEMP的後繼節點，回傳找到的後繼節點 */
NodeType *findNext(NodeType *nodeTemp)
{
	prev = node;
	if(nodeTemp != NULL)
		while(nodeTemp->link[0] != NULL){
			prev = nodeTemp;
			nodeTemp = nodeTemp->link[0];
		}
	return nodeTemp;
}

/* 尋找前行節點--尋找NODETEMP的前行節點，回傳找到的前行節點 */
NodeType *findPrev(NodeType *nodeTemp)
{
	prev = node;
	if(nodeTemp != NULL)
		while(nodeTemp->link[MAX-1] != NULL){
			prev = nodeTemp;
			nodeTemp = nodeTemp->link[MAX-1];
		}
	return nodeTemp;
}

/* 給予節點編號--使用前序遞迴方式給予每個節點編號 */
void preorderId(NodeType *tree)
{
	int i;
	if(tree != NULL){
		tree->id = idSeq++;
		for(i = 0; i <= tree->n; i++)
			preorderId(tree->link[i]);
	}
}

/* 輸出資料--使用前予遞迴方式輸出節點資料 */
void preorderNum(NodeType *tree)
{
	int i;
	char linkId;
	if(tree != NULL){
		/* 當節點鏈節為NULL，則顯示鏈結為0 */
		if(tree->link[0] == NULL) linkId = '0';
		else linkId = tree->link[0]->id;
		printf("  %c, %d, %c", tree->id, tree->n, linkId);
		for(i = 1; i <= tree->n; i++){
			if(tree->link[i] == NULL) linkId = '0';
			else linkId = tree->link[i]->id;
				printf(", (%d, %c)", tree->key[i], linkId);
		}
		printf("\n");
		for(i = 0; i <= tree->n; i++)
			preorderNum(tree->link[i]);
	}
}

/* 儲存資料至檔案--使用前序遞迴儲存資料 */
void preorderSave(NodeType *tree)
{
	int i;
	if(tree != NULL){
		for(i = 1; i <= tree->n; i++)
			fprintf(fptro, "%d\n", tree->key[i]);
		for(i = 0; i <= tree->n; i++)
			preorderSave(tree->link[i]);
	}
}