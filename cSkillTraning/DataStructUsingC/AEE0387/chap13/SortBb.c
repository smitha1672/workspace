/* File name: SortBb.c */
/* Version 4.0, June, 2017 */

#include <stdio.h>
void bubbleSort(int[], int);

int main(void)
{
	int data[20];
	int size = 0, i;

	printf("\nPlease enter number to sort ( enter 0 when end ):\n");
	printf("Number : ");
	do{    /* 要求輸入數字直到輸入數字為零 */
		scanf("%d", &data[size]);
	}while(data[size++] != 0);

	for(i = 0; i < 40; i++) printf("-");
	printf("\n");
	bubbleSort(data, --size);  /* --size用於將資料為零者排除 */

	for(i = 0; i < 40; i++) printf("-");
	printf("\nSorted data: ");
	for(i = 0; i < size; i++)
		printf("%d  ", data[i]);
	printf("\n");
	return 0;
}

void bubbleSort(int data[], int size)
{
	int i, j, k, temp, flag;
	for(i=0; i<size-1; i++) { /* 讓資料兩兩比較，將小的置於前 */
		flag=0;
		/* 印出第幾次的 Pass */ 
		printf("#%d pass: \n", i+1);
 
		for(j=0; j<size-i-1; j++) {
	        /* 當某一筆資料大於其下一筆資料時，將兩資料對調 */
			if(data[j] > data[j+1]){
				flag=1;
				temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			}

   			/* 印出每一次的 compare */ 
	   	    printf("   #%d compare: ", j+1);
 
	        /* 每一次的 compare 資料量會減 1，故以在迴圈中以size-i為結束點 */ 
	        for (k=0; k < size-i; k++)
			 printf("%d ", data[k]);
	        printf("\n");
		}
   	    /*印出每一次的 Pass 的最後的資料 */ 
	    printf("# pass finished: ");
		
	    for(k = 0; k < size; k++)
		    printf("%d ", data[k]);
	    printf("\n\n");
	    if(flag != 1)
	  	    break;
  	}
}