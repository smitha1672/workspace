/* File name: BellmanFord.c */
/* Version 4.0, June, 2017 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAXV 100   
#define Infinite 1073741823
long int A[MAXV+1][MAXV+1];
long int D[MAXV+1];
long int changed[MAXV+1];
int N;
void init();
void Output();
void BellmanFord();

int main()
{
     init();
     BellmanFord();
     getch();
     return 0;
}

void init()
{
      FILE *fptr;
      int i, j;
      long int weight;
      fptr = fopen("source.dat", "r");
      if ( fptr == NULL )	{
	      perror("source.dat");
	      exit(1);
	}
	fscanf(fptr, "%d", &N);       /*讀取圖形節點數*/
	for ( i=1; i<=N; i++ )
	      for ( j=1; j<=N; j++ )
	            A[i][j] = Infinite;  /*起始A[1..N][1..N]相鄰矩陣*/
      while ( fscanf(fptr, "%d %d %ld", &i, &j, &weight) != EOF )
	      A[i][j] = weight;      /*讀取i節點到j節點的權weight */
	fclose(fptr);
	/* 起始各陣列初值*/
	for( i =1; i<=N ; i++){
        D[i] = A[1][i]; /*記錄起始頂點至各頂點最短距離*/
		changed[i] = A[1][i];
	}
	changed[1] = 0;
	D[1] = 0;
	printf("		disk[%d]\n", N);
      for ( i=1 ; i<=N ; i++)
          printf("=====");
      printf("\n");
        for ( i=1; i<=N; i++ )
           printf("%4ld", i); 	  
         printf("\n");
        for ( i=1 ; i<=N ; i++)
         printf("-----");
	   printf("\n");
	   Output();
	   printf("\n");
}

void BellmanFord()
{
    int  i, u, k;
    for(k=1; k<= N-2; k++)
    {
         for(u=1; u<=N ; u++)
         {
	            for(i=1; i<=N ; i++){
                  if(D[u] > D[i] + A[i][u]){
			            if (changed[u] > D[i]+A[i][u])
				            changed[u] = D[i] + A[i][u];
			      }
                }
         }
         Output();
         printf("\n");
    }
    printf("\n");
    for ( i=1 ; i<=N ; i++)
	      printf("=====");
    printf("\n");
}

void Output(void)
{
	int i=0, j=0;
	for (j=1 ; j<=N ; j++){
	      if ( changed[j] == Infinite )
		      printf("  ∞");
		else{
			if (changed[j] != D[j] )
			      printf("  *%d", changed[j]);
			else
			      printf("%4ld", changed[j]);
		}
	}
	for(i=1 ; i<=N ; i++)
	      D[i] = changed[i];
}