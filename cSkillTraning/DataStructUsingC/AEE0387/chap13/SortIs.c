/* File name: SortIs.c */
/* Version 4.0, June, 2017 */

#include <stdio.h>

void insertionSort(int[], int);

int main()
{
	int data[20];
	int size = 0, i;
	printf("\nPlease enter number to sort ( enter 0 when end ):\n");
	printf("Number : ");
	do{    /* 要求輸入資料直到輸入為零 */
		scanf("%d", &data[size]);
	}  while(data[size++] != 0);
	for(i = 0; i < 50; i++) printf("-");
	printf("\n");
	insertionSort(data, --size);
	for(i = 0; i < 50; i++) printf("-");
	printf("\nSorted data: ");
	for(i = 0; i < size; i++)
		printf("%d  ", data[i]);
	printf("\n");
	return 0;
}

void insertionSort(int data[], int size)
{
	int base, compare, temp, i;
	printf("First data is %d\n\n", data[0]);
	for(base = 1; base < size; base++){
	/* 當資料小於第一筆，則插於前方，否則與後面資料比對找出插入位置 */
		temp = data[base];
		compare = base;
		printf("Insert data is %d\n", data[base]); 
		while(compare > 0 && data[compare-1] > temp){
			data[compare] = data[compare-1];
			compare--;
		}
		data[compare] = temp;
		printf("Ater #%d insertion: ", base);
		for(i = 0; i <= base; i++)
			printf("%d  ", data[i]);
		printf("\n\n");
	}
}