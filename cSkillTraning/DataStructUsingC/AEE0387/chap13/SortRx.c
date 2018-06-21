/* File name: SortRx.c */
/* Version 4.0, June, 2017 */

#include <stdio.h>

int main()
{
	int data[10] = {75, 23, 98, 44, 57, 12, 29, 64, 38, 82};
	int i, j, k = 0, n = 1, lsd, temp[10][10];
	int order[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	printf("\n<< Radix sort >>\n");
	printf("\nNumber : ");
	for(i = 0; i < 10; i++)
		printf("%d  ", data[i]);
	puts("");
	for(i = 0; i < 60; i++) printf("-");
	while(n <= 10){
		for(i = 0; i < 10; i++){
			lsd = ((data[i]/n) % 10);
			temp[lsd][order[lsd]] = data[i];  /* 依餘數將資料分類 */
			order[lsd]++;
		}
		printf("\nAccess : ");
		for(i = 0; i < 10; i++){
			if(order[i] != 0)
 /* 依分類後的順序將資料重新排列 */
				for(j = 0; j < order[i]; j++){
					data[k] = temp[i][j];
					printf("%d  ", data[k]);
					k++;
				}
			order[i] = 0;
		}
		n *= 10;
		k = 0;
	}
	puts("");
	for(i = 0; i < 60; i++) printf("-");
	printf("\nSorting: ");
	for(i = 0; i < 10; i++)
		printf("%d  ", data[i]);
	printf("\n");
	return 0;
}