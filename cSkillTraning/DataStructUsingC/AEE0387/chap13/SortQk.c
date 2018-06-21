/* File name: SortQk.c */
/* Version 4.0, June, 2017 */

#include <stdio.h>

void quickSort(int[], int, int, int);

int main()
{
	int data[20];
	int size = 0, i;

	/* 要求輸入資料直到輸入資料為零 */
	printf("\nPlease enter number to sort ( enter 0 when end ):\n");
	printf("Number : ");
	do{
		scanf("%d", &data[size]);
	}  while(data[size++] != 0);
	for(i = 0; i < 60; i++) printf("-");
	printf("\n");
	quickSort(data, 0, --size-1, size-1);
	for(i = 0; i < 60; i++) printf("-");
	printf("\nSorted data: ");
	for(i = 0; i < size; i++)
		printf("%d  ", data[i]);
	printf("\n");
	return 0;
}

void quickSort(int data[], int left, int right, int size)
{	
	/* left與right分別表欲排序資料兩端 */
	int lbase, rbase, temp, i;

	if(left < right){
		lbase = left+1;
		while(data[lbase] < data[left]) lbase++;
		rbase = right;
		while(data[rbase] > data[left]) rbase--;
		while(lbase < rbase){  /* 若lbase小於rbase，則兩資料對調 */ 			
			temp = data[lbase];
			data[lbase] = data[rbase];
			data[rbase] = temp;
			lbase++;
			while(data[lbase] < data[left]) lbase++;
			rbase--;
			while(data[rbase] > data[left]) rbase--;
		}
		temp = data[left]; 

/* 此時lbase大於rbase，則rbase的資料與第一筆對調 */
		data[left] = data[rbase];
		data[rbase] = temp;
		printf("Sorting .... : ");
		for(i = 0; i < size; i++)
			printf("%d  ", data[i]);
		printf("\n");
		quickSort(data, left, rbase-1, size);
		quickSort(data, rbase+1, right, size);
	}
}