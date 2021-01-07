/* File name: SortSh.c */
/* Version 4.0, June, 2017 */

#include <stdio.h>

void shellSort(int data[]);

int main()
{
	int data[11] = {0, 75, 23, 98, 44, 57, 12, 29, 64, 38, 82};
	int i;

	printf("\n<< Shell sort >>\n");
	printf("\nNumber : ");
	for(i = 1; i <= 10; i++)
		printf("%d  ", data[i]);
	puts("");
	for(i = 0; i < 60; i++) printf("-");
	shellSort(data);
	puts("");
	for(i = 0; i < 60; i++) printf("-");
	printf("\nSorting: ");
	for(i = 1; i <= 10; i++)
		printf("%d  ", data[i]);
	printf("\n");
	return 0;
}

void shellSort(int data[])
{
	int i, j, k, incr, temp;

	incr = 10/2;
	while(incr > 0){
		for(i = incr+1; i <= 10; i++){
			j = i - incr;
			while(j > 0)
				if(data[j] > data[j+incr]){  /* 比較每部份的資料 */
					/* 大小順序不對則交換 */
					temp = data[j];
					data[j] = data[j+incr];
					data[j+incr] = temp;
					j = j - incr;
				}
				else
					j = 0;
		}
		printf("\nAccess : ");
		for(k = 1; k <= 10; k++)
			printf("%d  ", data[k]); 		incr = incr/2;
	}
}