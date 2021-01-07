/* File name: Chanhash.c*/
/* Versioin 4.0, June, 2017 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

#define MAXNUM 100  /*最大資料筆數*/
#define PRIME 97  /*MAXNUM之質數*/
#define NOTEXISTED NULL

/*定義資料結構*/
typedef struct Person {
	long id;
	char name[21];
	struct Person *link;
} Student;

/*建立雜湊表串列*/
Student *Hashtab[MAXNUM];
/*函數原型宣告*/
long hashfun(long);
void insert();
void del();
Student *search(Student *, Student *);
void query();
void show();

int main()
{
	char *menuPrompt =
		"=== Hashing Table Program ==\n"
		"  1. Insert\n"
		"  2. Delete\n"
		"  3. Show\n"
		"  4. Search\n"
		"  5. Quit\n"
		"Please input a number : ";
	char menusele;
	int i;
	/*起始雜湊串列，將各串列指向NULL*/
	for ( i = 0; i< MAXNUM; i++)
		Hashtab[i] = NULL;
	do{
		printf("\n%s", menuPrompt);
		menusele = toupper(getchar());
		while (getchar()!='\n') continue;
		puts("");
		switch (menusele){
			case '1' :
					insert();
				break;
			case '2' :
				del();
				break;
			case '3' :
				show();
				break;
			case '4' :
				query();
				break;
			case '5' :
				puts("Bye Bye ^_^");
				break;
			default :
				puts("Invalid choice !!");
		}
	} while (menusele != '5' );
	return 0;
}

/*  雜湊函數:  */
/*  以除法運算傳求出記錄應儲存的位址  */
long hashfun(long key)
{
	return ( key % PRIME );
}

void insert()
{
	Student  *newnode;
	long index;
	/*輸入記錄*/
	newnode = ( Student *)malloc(sizeof(Student));
	newnode->link = NULL;
	printf("Enter id : ");
	scanf("%d", &newnode->id);
	while (getchar()!='\n') continue;
	printf("Enter Name : ");
	scanf("%s", newnode->name);
	while (getchar()!='\n') continue;
	/*利用雜湊函數求得記錄位址*/
	index = hashfun(newnode->id);
	/*判斷該串列是否為空，若為空則建立此鏈結串列*/
	if ( Hashtab[index] == NULL ){
		Hashtab[index] = newnode;
		printf("Node insert ok!\n");
	}
	else{
		/*搜尋節點是否已存在串列中
		  如未存在則將此節點加入串列前端*/
		if ((search(Hashtab[index], newnode)) == NOTEXISTED){
			newnode->link = Hashtab[index];
			Hashtab[index] = newnode;
			printf("Node insert ok!\n");
		}
		else
			printf("Record existed...\n");
	}
}

/*刪除節點函數*/
void del()
{
	Student *node , *nodeParent;
	long index;
	node = (Student *)malloc(sizeof(Student));
	printf("Enter ID : ");
	scanf("%d", &node->id);
	while (getchar()!='\n') continue;
	/*利用雜湊函數轉換記錄位址*/
	index  =  hashfun(node->id);
	/*搜尋節點是否存在並傳回指向該節點指標*/
	node  = search(Hashtab[index], node);
	if ( node == NOTEXISTED )
		printf("Record not existed ...\n");
	else{
		/*如節點為串列首，則將串列指向NULL
		  否則找到其父節點，並將父節點link向節點後端*/
		printf("ID : %d   Name : %s\n", node->id, node->name);
		printf("Deleting record....\n");
		if ( node == Hashtab[index] )
			Hashtab[index] = NULL;
		else{
			nodeParent = Hashtab[index];
			while ( nodeParent->link->id != node->id )
				nodeParent = nodeParent->link;
			nodeParent->link = node->link;
		}
		free(node);
	}
}

/* 搜尋節點函數，如找到節點則傳回指向該節點之指標，否則傳回NULL  */
Student *search(Student *linklist, Student *Node)
{
	Student *ptr = linklist;
	while (ptr != NULL && ptr->id != Node->id  )
		ptr = ptr->link;
	if ( ptr == NULL ) 
 		return NOTEXISTED;
	else
		return ptr;
}

/*查詢節點函數*/
void query()
{
	Student *queryNode;
	long index;
	queryNode = (Student *)malloc(sizeof(Student));
	printf("Enter ID : ");
	scanf("%d", &queryNode->id);
	while (getchar()!='\n') continue;
	index = hashfun(queryNode->id);
 
	/*搜尋節點*/
	queryNode = search(Hashtab[index], queryNode);
	if ( queryNode == NOTEXISTED )
		printf("Record not existed...\n");
	else{
		printf("ID : %d  Name : %s\n", 
		queryNode->id, queryNode->name);
	}
}

/* 顯示節點函數，從雜湊串列一一尋找是否有節點存在 */
void show()
{
	int i;
	Student *ptr;
	printf("%8s %8s %15s\n", "Bucket", "ID", "NAME");
	puts("-----------------------------------");
	for ( i = 0; i < MAXNUM;i++ ){
		/* 串列不為空，則將整串列顯示出*/
		if ( Hashtab[i] != NULL ){
			ptr = Hashtab[i];
			while (ptr) {
				printf("%8d %8d %15s\n", i, ptr->id, ptr->name);
				ptr = ptr->link;
			}
		}
	}
}