/* File name: Kruskal.c */
/* Version 4.0, June, 2017 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAXV 100  /*最大節點數*/
#define TRUE 1
#define FALSE 0

typedef struct {
	int vertex1;
	int vertex2;
	int weight;
	int edgeDeleted;
} Edge;

typedef struct {
	int vertex[MAXV];
	int edges;
} Graph;

Edge E[MAXV];
Graph T;
int totalVertex;
int totalEdge;
int adjmatrix[MAXV][MAXV];  /*store matrix weight*/
void kruskal();
void addEdge(Edge );
void buildAdjmatrix();
Edge mincostEdge();
int cyclicT(Edge e);
void showEdge();

int main()
{
	Edge e;
	int i , j , weight;
	buildAdjmatrix();
	for (i = 1; i <= totalVertex; i++)
		for ( j = i+1; j <= totalVertex; j++ ){
			weight = adjmatrix[i][j];
			if ( weight != 0 ){
				e.vertex1 = i;
				e.vertex2 = j;
				e.weight = weight;
				e.edgeDeleted = FALSE;
				addEdge(e);
			}
		}
	showEdge();
	/*init T*/
	for ( i = 1; i <= totalVertex; i++ )
		T.vertex[i] = 0;
	T.edges = 0;
	puts("\nMinimum cost spanning tree using Kruskal");
	puts("-------------------------------------------");
	kruskal();
	getchar();
	return 0;
}

void buildAdjmatrix()
{
	FILE *fptr;
	int vi, vj;
	fptr = fopen("kruskal.dat", "r");
	if ( fptr == NULL ){
		perror("kruskal.dat");
		exit(0);
	}
/*讀取節點總數*/
	fscanf(fptr, "%d", &totalVertex);
	for (vi = 1; vi <= totalVertex; vi++)
		for ( vj = 1; vj <= totalVertex; vj++ )
			fscanf(fptr, "%d", &adjmatrix[vi][vj]);
	fclose(fptr);
}

void addEdge( Edge e)
{
	E[++totalEdge] = e;
}

void showEdge()
{
	int  i = 1;

printf("total vertex = %d  ", totalVertex);
	printf("totalEdge = %d\n", totalEdge);
	while ( i <= totalEdge ){
		printf("V%d  <----->  V%d   weight= %d\n", E[i].vertex1, 
			    E[i].vertex2, E[i].weight);
		i++;
	}
}

Edge mincostEdge()
{
	int i , min;
	long minweight = 10000000;
	for ( i = 1; i <= totalEdge; i++ ){
		if (!E[i].edgeDeleted && E[i].weight < minweight){
			minweight = E[i].weight;
			min = i;
		}
	}
	E[min].edgeDeleted = TRUE;
	return E[min];
}

void kruskal()
{
	Edge e;
	int loop = 1;
	while ( T.edges != totalVertex - 1  )	{
		e = mincostEdge();
		if ( !cyclicT(e) ){
			printf("%dth min edge : ", loop++);
			printf("V%d  <----->  V%d  weight= %d\n", 
					e.vertex1, e.vertex2, e.weight);
		}
	}
}

int cyclicT(Edge e)
{
	int v1 = e.vertex1;
	int v2 = e.vertex2;
	
T.vertex[v1]++;
	T.vertex[v2]++;
	T.edges++;
if ( T.vertex[v1] >= 2 && T.vertex[v2] >= 2 ){
		if(v2 == 2)
			return FALSE;
		T.vertex[v1]--;
		T.vertex[v2]--;
		T.edges--; 		return TRUE;
	}
	else
		return FALSE;
}