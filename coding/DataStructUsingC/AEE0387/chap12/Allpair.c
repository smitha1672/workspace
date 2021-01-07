/* File name: Allpair.c*/
/* Version 4.0, June, 2017 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAXV 10  
#define Infinite 1073741823
long int A[MAXV+1][MAXV+1];
long int D[MAXV+1][MAXV+1];
long int Origin[MAXV+1][MAXV+1];
int N;
int first = 1;
void init();
void Output();
void Changed(int num);
void AllPairLength(int N);

int main()
{
	init();
	AllPairLength(N);
	getch();
	return 0;
}

void init()
{
	FILE *fptr;
	int i, j;
	long int weight;
	fptr = fopen("allpair.dat", "r");
	if ( fptr == NULL )	{
		perror("allpair.dat");
		exit(1);
	}
	fscanf(fptr, "%d", &N);       
	for ( i=1; i<=N; i++ )
		for ( j=1; j<=N; j++ )
			A[i][j] = Infinite;  
	while ( fscanf(fptr, "%d %d %ld", &i, &j, &weight) != EOF )
		A[i][j] = weight;      
	fclose(fptr);
	for ( i = 1; i <= N; i++){
		for ( j = 1; j <= N; j++ ){
			D[i][j] = A[i][j]; 
		}
		D[i][i] = 0;
	}
	printf("If the distance is changed, \nthen it will have '*' symbol !!\n");
	printf("    A#%i", 0);
	Output();
}

void AllPairLength(int N)
{
	int i, j, k;
	first = 0;
		
	for(k=1; k<=N; k++){
		for(i=1; i<=N; i++){
			for(j=1; j<=N; j++){
				if ((D[i][k] + D[k][j]) < D[i][j]){
					D[i][j] = D[i][k] + D[k][j];
				}
			}
		}
	printf("\n    A#%i", k);
	Changed(k);
	Output();
	}
}

void Output()
{
	int i=0, j=0;

	printf("\n");
	for ( i=1 ; i<=N ; i++)
		printf("======");
	printf("\n");
	printf("    j");
	for ( i=1; i<=N; i++ )
		printf("%4ld", i);
	printf("\n");
	for ( i=1 ; i<=N ; i++)
		printf("------");
	printf("\n");
	for ( i =1; i<=N ; i++){
		if (i == (1+N)/2)
			printf("i");
		else
			printf(" ");
	printf("%4ld", i);
	for ( j=1; j<=N; j++ )
		if ( D[i][j] == Infinite )
			printf("  ∞");
		else{
			if (Origin[i][j] != D[i][j] && first != 1)
				printf("  *%d", D[i][j]);
			else
				printf("%4ld", D[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for ( i=1 ; i<=N ; i++)
		printf("======");
	printf("\n");
	getch();
}

void Changed(int num)
{
	int i, j, k;
	switch(num){
	case 1:
		for ( i = 1; i <= N; i++){
			for ( j = 1; j <= N; j++ ){
				Origin[i][j] = A[i][j];
			}
			Origin[i][i] = 0;
		}
		break;
	default:
		for(k=num-1; k<=num-1 ; k++){
			for(i=1; i<=N; i++){
				for(j=1; j<=N; j++){
					if ((Origin[i][k] + Origin[k][j]) < Origin[i][j])
						Origin[i][j] = Origin[i][k] + Origin[k][j];
				}
			}
		}
		break;
	}
}