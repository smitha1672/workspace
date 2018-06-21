/* File name: Queen4.c */
/* Version 4.0, June, 2017 */

#include <stdio.h>
#include <conio.h>

#define TRUE 1
#define FALSE 0
#define MAXQUEEN 4
#define ABS(x) ((x>0) ?(x): -(x))  /*求x之絕對值*/

/*存放4個皇后之列位置, 陣列註標為皇后的行值置*/
int queen[MAXQUEEN];
int totalSolution = 0;  /*計算共有幾組解*/

/*函數原型宣告*/
void place(int);
int attack(int, int);
void outputSolution();

int main()
{
	place(0);  /*從第0個皇后開始擺放至棋盤*/
	printf("\n");
	return 0;
}

void place(int q)
{
	int i;
	i = 0;

	while ( i < MAXQUEEN ){
		if ( !attack(i, q)){  /*皇后未受攻擊*/
			queen[q] = i;  /*儲存皇后所在的列位置*/
			/*判斷是否找到一組解 */
			if ( q == 3 )
				outputSolution();  /*列出此組解*/
			else
				place(q+1);  /*否則繼續擺下一個皇后*/
		}
		i++;
	}
}

/* 測試在(row, col)上的皇后是否遭受攻擊
   若遭受攻擊則傳回值為1，否則傳回0 */
int attack(int row, int col)
{
	int i, atk = FALSE;
	int offset_row, offset_col;
	i = 0;

	while ( !atk && i < col ){
		offset_col = ABS(i - col);
		offset_row = ABS(queen[i] - row);
		/*判斷兩皇后是否在同一列, 皇后是否在對角線上*/
		/*若皇后同列或在對角線上則產生攻擊, atk ==TRUE */
		atk = (queen[i] == row)||(offset_row == offset_col);
		i++;
	}
	return atk;
}

/*列出4個皇后之解*/
void outputSolution()
{
	int x, y;

	totalSolution += 1;
	printf("Solution #%3d\n\t", totalSolution);
	for ( x = 0; x < MAXQUEEN; x++ ){
		for ( y =0; y< MAXQUEEN;y++ )
			if ( x == queen[y] )
				printf("Q");
			else
				printf("-");
		printf("\n\t");
	}
	printf("\n");
}