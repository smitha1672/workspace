/* File name: Factor.c */
/* Version 4.0, June, 2017 */

#include <stdio.h>
#include <conio.h>
#include <ctype.h>

/* 函數原型宣告 */
long Factorial(long);

int main()
{
    char ch;
    long n;
    printf("-----Factorial counting Using Recursive----");
    do{
        printf("\nEnter a number( 0<=n<=12 ) to count n!: ");
        scanf("%ld", &n);
        /* n 值在一般系統中超過13會產生overflow 得到不正確的值*/
        if ( n < 0 || n >12 )
            printf("input out of range !\n");
        else
            printf("%ld! = %ld\n", n, Factorial(n) );
        printf("Continue (y/n) ? ");
        while(getchar()!= '\n') continue;
        ch = toupper(getchar());
    } while (ch == 'Y' );
    return 0;
}

/* 利用遞迴呼叫自己計算N 階層*/
long Factorial(long n)
{
    if ( n == 1 || n== 0)    /* 設定結束點 */
        return (1);
    else
        return( n * Factorial(n-1));
}