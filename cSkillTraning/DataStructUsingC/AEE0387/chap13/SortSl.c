/* File name: SortSl.c */
/* Version 4.0, June, 2017 */

#include <stdio.h>

void selectionSort(int[], int);

int main()
{
	int data[20];
	int size = 0, i;
	/* 要求輸入資料直到輸入為零 */
	printf("\nPlease enter number to sort ( enter 0 when end ):\n");
	printf("Number : ");
	do{
		scanf("%d", &data[size]);
	}  while(data[size++] != 0);
	for(i = 0; i < 50; i++) printf("-");
	printf("\n");
	selectionSort(data, --size);
	for(i = 0; i < 50; i++) printf("-");
	printf("\nSorting: ");
	for(i = 0; i < size; i++)
		printf("%d  ", data[i]);
	printf("\n");
	return 0;
}

void selectionSort(int data[], int size)
{
	int base, compare, min, temp, i;
	for(base = 0; base < size-1; base++){
	/* 將目前資料與後面資料中最小的對調 */
		min = base;
		for(compare = base+1; compare < size; compare++)
			if(data[compare] < data[min])
				min = compare;
		printf("#%d selected data is : %d\n", base+1, data[min]);
		temp = data[min];
		data[min] = data[base];
		data[base] = temp;

		for(i = 0; i < size; i++)
			printf("%d  ", data[i]);
		printf("\n\n");
	}
}