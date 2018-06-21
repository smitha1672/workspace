/* File name: ShPath.c */
/* Version 4.0, June, 2017 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAXV 100   /*最大節點數*/
#define VISITED 1
#define NOTVISITED 0
#define Infinite 1073741823
/* A[1..N][1..N] 為圖形的相鄰矩陣 */
/* D[i] i=1..N 用來儲存某起始頂點到i節點的最短距離 */
/* S[1..N] 用來記錄頂點是否已經拜訪過 */
/* P[1..N] 用來記錄最近經過的中間節點 */
long int A[MAXV+1][MAXV+1];
long int D[MAXV+1];
long int S[MAXV+1], P[MAXV+1];
int source , sink , N;
int step = 1;
int top = -1;         /*堆疊指標*/
int Stack[MAXV+1];   /*堆疊空間*/
void init();
int minD();
void outputStep();
void outputPath();
void Push(int);
int Pop();

int main()
{
int t, I;
	
     init();
outputStep();
     for ( step =2;step <=N; step++ )
     {
		/* minD 傳回一值t使得D[t] 為最小 */
		t = minD();
		S[t] = VISITED;
		/* 找出經過t點會使路徑縮短的節點*/
		for ( I=1; I <= N; I++ )
			if ( (S[I] == NOTVISITED) && (D[t]+A[t][I] <= D[I]) )
            {
				D[I] = D[t] + A[t][I];
				P[I] = t;
			}
		outputStep();
	 }
	 outputPath();
 	 return 0;
}

void init()
{	
	FILE *fptr;
	int i, j;
	long int weight;
	
      fptr = fopen("shPath.dat", "r");
	if ( fptr == NULL )	{
		perror("shPath.dat");
		exit(1);
	}
	fscanf(fptr, "%d", &N);       /*讀取圖形節點數*/
	for ( i=1; i<=N; i++ )
		for ( j=1; j<=N; j++ )
			A[i][j] = Infinite;  /*起始A[1..N][1..N]相鄰矩陣*/
	while ( fscanf(fptr, "%d %d %d", &i, &j, &weight) != EOF )
		A[i][j] = weight;      /*讀取i節點到j節點的權weight */
	fclose(fptr);
      printf("Enter source node : ");
	scanf("%d", &source);
	printf("Enter sink node : ");
	scanf("%d", &sink);
	/* 起始各陣列初值*/
	for ( i = 1; i <= N; i++ ){
		S[i] = NOTVISITED; /*各頂點設為尚未拜訪*/             
		D[i] = A[source][i]; /*記錄起始頂點至各頂點最短距離*/
		P[i] = source;       
}
	S[source] = VISITED;  /*始起節點設為已經走訪*/
	D[source] = 0;
}

int minD()
{
	int i, t;
	long int minimum = Infinite;

	for ( i=1;i<=N;i++ )
		if ( (S[i] == NOTVISITED) && D[i] < minimum ){
			minimum = D[i];
			t = i;
		}
	return t;
}

/* 顯示目前的D陣列與P陣列狀況 */
void outputStep()
{
	int i;
	printf("\n Step #%d", step);
	printf("\n===========================================\n");
	for ( i=1; i<=N; i++ )
		printf("  D[%d]", i);
	printf("\n");
	for ( i=1; i<=N; i++ ) 		if ( D[i] == Infinite )
		printf("  ----");
	else
		printf("%6d", D[i]);
      printf("\n===========================================\n");
	for ( i=1; i<=N; i++ )
		printf("  P[%d]", i);
	printf("\n");
	for ( i=1; i<=N;i++ )
		printf("%6d", P[i]);
	printf("\n");
}

/*顯示最短路徑*/
void outputPath()
{
	int node = sink;

	/*判斷是否起始頂點等於終點或無路徑至終點*/  
	if ( (sink == source) || (D[sink] == Infinite) ){
		printf("\nNode %d has no Path to Node %d", source, sink);
		return;
	}
	printf("\n");
	printf(" The shortest  Path from V%d to V%d :", source, sink);
	printf("\n------------------------------------------\n");
	/*由終點開始將上一次經過的中間節點推入堆疊至到起始節點*/ 
	printf("  V%d", source);
	while ( node != source ){
		Push(node);
		node  = P[node];
	}
	while( node != sink){
		node = Pop(); 		
		printf(" --%d-->", A[ P[node] ][node]);
		printf("V%d", node);
	}
	printf("\n Total length : %d\n", D[sink]);
}



void Push(int value)
{
	if ( top >= MAXV )	{
		printf("Stack overflow!\n");
		exit(1);
	}
	else
		Stack[++top] = value;
}

int Pop()
{
	if ( top < 0 ){
		printf("Stack empty!\n");
		exit(1);
	}
	else
		return Stack[top--];
}