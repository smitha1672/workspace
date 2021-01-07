/* File name: SearchB.c */
/* Version 4.0, June, 2017 */

#include <stdio.h>

void binarySearch(int data[], int input);

int main()
{
	int data[11] = {0, 12, 23, 29, 38, 44, 57, 64, 75, 82, 98};
	int i, input;

	printf("\n<< Binary search >>\n");
	printf("\nSorted data: ");
	for(i = 1; i < 11; i++)
		printf("%d  ", data[i]);
	puts("");
	printf("\nWhat number do you want to search ? ");
	scanf("%d", &input);
	printf("\nSearch.....\n");
	binarySearch(data, input);
	printf("\n");
	return 0;
}

void binarySearch(int data[], int input)
{
	int l = 1, n = 10, m, cnt = 0, ok = 0;
	m = (l + n)/2;     /* 鍵值在第M筆 */
	while(l <= n && ok == 0){
		printf("\nData when searching #%2d time(s)is %d !", ++cnt, data[m]);
		if(data[m] > input){/* 欲搜尋的資料小於鍵值，則資料在鍵值的前面 */
			n = m - 1;
			printf(" ---> Choice number is smaller than %d", data[m]);
		}
		else                /* 否則資料在鍵值的後面 */
			if(data[m] < input)	{
				l = m + 1;
					printf(" ---> Choice number is bigger than %d", data[m]);
			}
			else{
					printf("\n\nFound, %d is the %dth record in data !", input, m);
				ok = 1;
			}
		m = (l + n)/2;
	}
	if(ok == 0)
		printf("\n\nSorry, %d not found !", input);
}