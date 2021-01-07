/* File name: Hashtab.c  */
/* Version 4.0, June, 2017 */

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#define MAXNUM 100  /*最大資料筆數*/
#define PRIME 97  /*最接近MAXNUM的質數*/

/*定義資料結構*/
typedef struct  Person {
	int  id;
	char name[21];
} Student;

/*建立雜湊表*/
Student Hashtab[MAXNUM];
/*函數原型宣告*/
long hashfun(long);
void insert();
void del();
void show();
long search();
void solveColliollision(Student, long);

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
	/*清除雜湊表中id的內容, id為0代表該桶為空的*/
	for ( i = 0; i< MAXNUM; i++)
		Hashtab[i].id = 0;
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
				search();
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
	Student node;
	long index;
	/*輸入記錄*/
	printf("Enter ID : ");
	scanf("%d", &node.id);
	while (getchar()!='\n') continue;
	printf("Enter Name : ");
	scanf("%s", node.name);
	while (getchar()!='\n') continue;
	/*利用雜湊函數取得儲存記錄位址*/
	index = hashfun(node.id);
	/* 判斷雜湊表該(index)位址是否已有資料
	   0代表該位址為空，否則即發生碰撞 */
	if ( Hashtab[index].id == 0 ){
		Hashtab[index].id = node.id;
		strcpy(Hashtab[index].name, node.name);
		printf("Node insert ok!\n");
	}
	else
		solveColliollision(node, index);
}

/* 利用線性探測解決碰撞 */
void solveColliollision(Student colNode, long i)
{
	long j;

	j = i;
	while ( Hashtab[j].id != colNode.id && Hashtab[j].id !=0 ){
		j = (j+1) % PRIME;  /* 將雜湊表視為環狀 */
		if ( j == i ){
			printf("Hashtab is overflow...\n");
			return;
		}
	}
	/* 判斷該位址是否已有資料*/
	if ( Hashtab[j].id == 0 ){
		Hashtab[j].id = colNode.id;
		strcpy(Hashtab[j].name, colNode.name);
		printf("Node insert ok!\n");
	}
	else
		printf("Record existed in Hashtab!\n");
}

/* 顯示雜湊表中之資料 */
/* 從雜湊表第0桶開始尋找至最後一桶 */
/* 一一比對是否該桶有存放資料 */
void show()
{
	long i;
	puts("Bucket         ID            Name");
	puts("---------------------------------");
	for ( i = 0; i < MAXNUM; i++ ){
		/*判斷該位址是否有資料 */
		if (Hashtab[i].id != 0 ){
			printf("%5d  %10d %15s\n", i, Hashtab[i].id, 
			Hashtab[i].name);
		}
	}
}

void del()
{
	long index;
	/* 先搜尋記錄 */
	index = search();
	/* 判斷記錄是否存在 */
	if ( index != 0 ){
		printf("Deleting record....\n");
		Hashtab[index].id = 0;
	}
}
/* 搜尋記錄函數 */
long search()
{
	long id, index , j;
	/* 輸入欲搜尋記錄之學生id */
	printf("Enter ID : ");
	scanf("%d", &id);
	while (getchar()!='\n') continue;
	/* 轉換該記錄在雜湊表中之位址 */
	index = hashfun(id);
	j = index;
	while ( Hashtab[j].id != id && j != index ){
		j = ( j+1 ) % PRIME;
	}
	/* 判斷資料是否存在, 有則傳回該記錄在雜湊表中
	   之位址以作刪除函數參考，否則傳回0       */
	if ( Hashtab[j].id == id){
		printf("ID : %d    Name : %s\n", 
		Hashtab[j].id, Hashtab[j].name);
		return j;
	}
	else{
		printf("Can't find record !\n");
		return 0;
	}
}