/* File name: FibIterative.c */
/* Version 4.0, June, 2017 */

#include <stdio.h>
#include <conio.h>
#include <ctype.h>

/* 函數原型宣告 */
long Fibonacci(long);

int main()
{
    char ch;
    long n;
    printf("-----Fibonacci numbers Using Iterative-----");
    do{
        printf("\nEnter a number(n>=0) : ");
        scanf("%ld", &n);
        /* n 值大於 0 */
        if ( n < 0 )
            printf("Input number must be > 0!\n");
        else
            printf("Fibonacci(%ld) = %ld\n", n, Fibonacci(n));
        printf("Continue (y/n) ? ");
        while (getchar()!='\n') continue;
        ch = toupper(getchar());
    } while (  ch == 'Y');
    return 0;
}

long Fibonacci(long n)
{
    long backitem1;    /*前一項值*/
    long backitem2;    /*前二項值*/
    long thisitem;     /*目前項數值*/
    long i;
    if (n == 0)    /* 費氏數列第0項為0 */
        return (0);
    else if (n == 1)    /* 第二項為1 */
        return (1);
    else{
        backitem2 = 0;
        backitem1 = 1;
        /* 利用迴圈將前二項相加後放入目前項 */
        /* 之後改變前二項的值至到第n項求得 */
        for ( i = 2; i <= n; i++ ){
            /* F(i) = F(i–1) + F(i–2) */
            thisitem = backitem1 + backitem2;
            /*改變前二項之值*/
            backitem2 = backitem1;
            backitem1 = thisitem;
        }
        return (thisitem);
    }
}
