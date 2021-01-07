/* File name: Fib.c */
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
    printf("-----Fibonacii numbers Using Recursive-----");
    do{
        printf("\nEnter a number(n>=0) : ");
        scanf("%ld", &n);
        /* n值大於0 */
        if ( n < 0 )
            printf("Number must be > 0\n");
        else
            printf("Fibonacci(%ld) = %ld\n", n, Fibonacci(n));
        printf("Contiune (y/n) ? ");
        while (getchar()!='\n') continue;
        ch = toupper(getchar());
    } while ( ch == 'Y' );
    return 0;
}

/* 利用遞迴函數呼叫本身函數來計算Fibonacci numbers*/
long Fibonacci(long n)
{
    if ( n == 0)  /*第0項為 0 */
        return (0);
    else if ( n == 1 ) /*第1項為 1 */
        return (1);
    else  /*遞迴呼叫函數 第N項為n–1 跟 n–2項之和*/
        return Fibonacci(n-1) + Fibonacci(n-2);
}