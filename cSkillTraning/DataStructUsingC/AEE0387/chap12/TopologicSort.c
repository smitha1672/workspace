/* File name: TopologicSort.c */
/* Version 4.0, June, 2017 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAXV 100  /*最大節點數*/
#define TRUE 1
#define FALSE 0

/*定義資料結構*/
typedef struct nodeTag {
	int vertex;
	struct nodeTag *link;
} Node;

Node *adjlist[MAXV+1];  /*宣告相鄰串列*/
int visited[MAXV+1];  /*記錄頂點是否已拜訪*/
int TopOrder[MAXV+1];
int N;
int place;
void buildAdjlist();
void showAdjlist();
void topological();
void topSort(int);
Node *searchlast(Node *);

int main()
{
	int i;
	
	buildAdjlist(); /*以相鄰串列表示圖形*/
	showAdjlist();  /*顯示串列之資料*/
	topological();     /*圖形之蹤向優先搜尋，以頂點1為啟始頂點*/
	puts("\n------Toplogical order sort------");
	for ( i = 0; i < N; i++ )
		printf("V%d ", TopOrder[i]);
	getch();
	return 0;
}

void buildAdjlist()
{
	FILE *fptr;
	Node *node, *lastnode;
	int vi, vj;
	fptr = fopen("topSort.dat", "r");
	if ( fptr == NULL )	{
		perror("topSort.dat");
		exit(0);
	}
/*讀取節點總數*/
	fscanf(fptr, "%d", &N);
	for ( vi = 1; vi <= N; vi++){
		/*設定陣列及各串列啟始值*/
		adjlist[vi] = (Node *)malloc(sizeof(Node));
		adjlist[vi]->vertex = vi;
		adjlist[vi]->link = NULL;
	}
/*讀取節點資料*/
	while( fscanf(fptr, "%d %d", &vi, &vj) != EOF)	{
		node = (Node *)malloc(sizeof(Node));
		node->vertex = vj;
		node->link = NULL;
		if ( adjlist[vi]->link == NULL)
			adjlist[vi]->link = node;
		else{
			lastnode = searchlast(adjlist[vi]);
			lastnode->link = node;
		}
	}
	fclose(fptr);
}

/*顯示各相鄰串列之資料*/
void showAdjlist()
{
	int v;
	Node *ptr;
	puts("Head    adjacency nodes");
	puts("------------------------------");
	for (v = 1; v <= N; v++){
			printf("V%d ", adjlist[v]->vertex);
		ptr = adjlist[v]->link;
		while ( ptr != NULL ){
			printf("--> V%d ", ptr->vertex);
			ptr = ptr->link;
		}
		printf("\n");
	}
}

/*圖形之蹤向優先搜尋*/
void topological()
{
	int v;
	for ( v = 1;v <= N; v++)
		visited[v] = FALSE;
	place = N;
	for ( v = 1; v <= N; v++ )
		if ( !visited[v] )
			topSort(v);
}

void topSort(int k)
{
	Node *ptr;
	int w;

	visited[k] = TRUE;          /*設定v頂點為已拜訪過*/
	ptr = adjlist[k]->link;     /*拜訪v相鄰頂點*/
	while ( ptr != NULL ){
		w = ptr->vertex; /* w 為v的立即後繼者 */ 
		if ( !visited[w] )
			topSort(w);
		ptr = ptr->link;
	}
	TopOrder[--place] = k;
}

/*搜尋串列最後節點函數*/
Node *searchlast( Node *linklist )
{
	Node *ptr;
	
	ptr = linklist;
	while ( ptr->link != NULL ) ptr = ptr->link;
	return ptr;
}