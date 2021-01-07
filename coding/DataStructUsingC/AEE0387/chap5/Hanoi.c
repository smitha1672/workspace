/* File name: Hanoi.c */
/* Version 4.0, June, 2017 */

#include <stdio.h>
#include <conio.h>

/* 函數原型宣告 */
void HanoiTower(int , char, char, char);

int main()
{

	int n;
	char A = 'A' , B = 'B' , C = 'C';
	printf("-----Hanoi Tower Implementation----\n");
	/*輸入共有幾個盤子在A柱子中*/
	printf("How many disks in A ? ");
	scanf("%d", &n);
	if ( n == 0 )
		printf("no disk to move\n");
	else
		HanoiTower(n, A, B, C);
	return 0;
}

/* 遞迴函數呼叫求河內塔之解 */
void HanoiTower(int n, char a, char b, char c)
{
	if ( n == 1 )
		printf("Move disk 1 from %c -> %c\n", a, c);
	else{
		/*將A上n-1個盤子借助C移至B */
		HanoiTower(n-1, a, c, b);
		printf("Move disk %d from %c -> %c\n", n, a, c);
		/*將B上n-1個盤子借助A移至C */		HanoiTower(n-1, b, a, c);
	}
}