/*	File name: LifeGame.c
	Version 4.0, June, 2017
	Description : Game of Life Implementation
	生命細胞遊戲實作				*/
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#define MAXROW 10
#define MAXCOL 25
#define DEAD 0
#define ALIVE 1
int map[MAXROW][MAXCOL], newmap[MAXROW][MAXCOL];
int Generation;
/*函數原型宣告*/
void init();
int Neighbors();
void outputMap();
void Copymap();

int main()
{
    int row , col;
    char ans;
    
    init();   /*起始map */
    outputMap();
    do{
        /*	計算每一個(row, col)之cell 的鄰居個數
         依此個數決定其下一代是生是死。
         將下一代的map暫存在newmap以防overwrite map。*/
        for ( row = 0; row < MAXROW; row++ )
            for ( col = 0; col < MAXCOL; col++ )
                switch(Neighbors(row, col) ){
                    case 0 :
                    case 1 :
                    case 4 :
                    case 5 :
                    case 6 :
                    case 7 :
                    case 8 :
                        newmap[row][col] = DEAD;
                        break;
                    case 2 :
                        newmap[row][col] = map[row][col];
                        break;
                    case 3 :
                        newmap[row][col] = ALIVE;
                        break;
                }
        Copymap();  /*將newmap copy to map */
        do {
            printf("\nContinue next Generation (y/n)? ");
            ans = toupper(getchar());
            while (getchar()!='\n') continue;
            if ( ans == 'Y' || ans == 'N' )
                break;
        } while (1);
        if ( ans == 'Y' ) outputMap();
    } while (ans == 'Y');
    printf("\n");
    return 0;
}

void init()
{
    int row, col;
    
    /*起始map狀態, 一開始cells皆會DEAD */
    for ( row = 0; row < MAXROW; row++ )
        for ( col = 0; col < MAXCOL; col++ )
            map[row][col] = DEAD;
    
    printf("Game of life Program \n");
    printf("Enter (x, y) where (x, y) is a living cell\n");
    printf(" 0 <= x <= %d , 0 <= y <= %d\n", MAXROW-1, MAXCOL-1);
    printf("Terminate with (x, y) = ( -1, -1)\n");
    /* 輸入活細胞之位置, 以(-1, -1)結束輸入 */
    do{
        scanf("%d %d", &row, &col);
        while (getchar()!='\n') continue;
        if ( 0 <= row && row < MAXROW && 0 <= col && col < MAXCOL)
            map[row][col] = ALIVE;
        else
            printf("(x, y) exceeds map ranage!\n");
    } while ( row != -1 || col != -1 );
}

int Neighbors(int row, int col)
{
    int count = 0, c, r;
    /*	計算每一個cell的鄰居個數
     因為cell本身亦被當做鄰居計算
     故最後還要調整	*/
    for ( r = row -1; r <= row +1; r++ )
        for ( c = col -1;  c <= col +1; c++ ){
            if (r < 0 || r >= MAXROW || c < 0 || c >= MAXCOL)
                continue;
            if ( map[r][c] == ALIVE )
                count++;
        }
    /*調整鄰居個數*/
    if ( map[row][col] == ALIVE  )
        count--;
    return count;
}

/*顯示目前細胞狀態*/
void outputMap()
{
    int row , col;
    printf("\n\n%20cGame of life cell status\n", ' ');
    printf("%20c------Generation %d-------\n", ' ', ++Generation);
    for ( row = 0; row < MAXROW; row++ ){
        printf("\n%20c", ' ');
        for ( col = 0; col < MAXCOL; col++ )
            if ( map[row][col] == ALIVE )
                putchar('@');
            else
                putchar('-');
    }
}

/*將newmap copy 至map 中*/
void Copymap()
{
    int row , col;
    for ( row = 0; row < MAXROW; row++ )
        for ( col = 0; col < MAXCOL; col++ )
            map[row][col] = newmap[row][col];
}
