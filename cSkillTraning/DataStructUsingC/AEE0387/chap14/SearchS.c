/* File name: SearchS.c */
/* Version 4.0, June, 2017 */

#include <stdio.h>

void sequentialSearch(int data[], int input);

int main()
{
	int data[10] = {75, 23, 98, 44, 57, 12, 29, 64, 38, 82};
	int i, input;

	printf("\n<< Squential search >>\n");
	printf("\nData: ");
	for(i = 0; i < 10; i++)
		printf("%d  ", data[i]);
	puts("");
	printf("\nPlease enter a number from data: ");
	scanf("%d", &input);
	printf("\nSearch.....\n");
	sequentialSearch(data, input);
	printf("\n");
    return 0;
}

void sequentialSearch(int data[], int input)
{
	int i;
	for(i = 0; i < 10; i++){  /* 依序搜尋資料 */
		printf("\nData when searching #%2d time(s) is %d !", i+1, data[i]);
		if(input == data[i]) break;
	}
	if(i == 10)
		printf("\n\nSorry, %d not found !", input);
	else
		printf("\n\nFound, %d is the %dth record in data!", input, i+1);

}