/* File name: Intopost.c */
/* Version 4.0, June, 2017 */

#include <stdio.h>
#define MAX 20
void infixToPostfix(char [], int);  /* 由中序轉後序函數 */
int compare(char, char);  /* 比較兩個運算子函數 */

/* 在中序表示法佇列及暫存堆疊中，運算子的優先順序表，其優先值為INDEX/2 */
char infixPriority[9] = {'#', ')', '+', '-', '*', '/', '^', ' ', '('}; 
char stackPriority[8] = {'#', '(', '+', '-', '*', '/', '^', ' '};

int main()
{
	int rear = -1;
	char infixQ[MAX];  /* 儲存使用者輸入中序式的佇列 */
	printf("*********************************\n");
	printf("      -- Usable operator --\n");
	printf(" ^: Exponentiation\n");
	printf(" *: Multiply      /: Divide\n");
	printf(" +: Add           -: Subtraction\n");
	printf(" (: Left Brace    ): Right Brace\n");
	printf("*********************************\n");
	printf("Please enter infix expression: ");
	while(infixQ[rear] != '\n')
		infixQ[++rear] = getchar();
	infixQ[rear] = '#';  /* 於佇列結束時加入#為結束符號 */
	printf("Postfix expression: ");
	infixToPostfix(infixQ, rear);
	printf("\n");
	return 0;
}

void infixToPostfix(char infixQ[], int rear)
{
	int top = 0, ctr;
	char stackT[MAX];  /* 用以儲存還不必輸出的運算子 */
	stackT[top] = '#'; /* 於堆疊最底下加入#為結束符號 */
	for(ctr = 0; ctr <= rear; ctr++){
		switch(infixQ[ctr]){
			/* 輸入為)，則輸出堆疊內運算子，直到堆疊內為( */
			case ')':
				while(stackT[top] != '(')
					printf("%c", stackT[top--]);
				top--;
				break;
			/* 輸入為#，則將堆疊內還未輸出的運算子輸出 */
			case '#':
				while(stackT[top] != '#')
					printf("%c", stackT[top--]);
				break;
			/* 輸入為運算子，若小於TOP在堆疊中所指運算子，則將堆疊
			   所指運算子輸出，若大於等於TOP在堆疊中所指運算子，則
			   將輸入之運算子放入堆疊 */
			case '(':
			case '^':
			case '*':
			case '/':
			case '+':
			case '-':
				while(compare(stackT[top], infixQ[ctr]))
					printf("%c", stackT[top--]);
				stackT[++top] = infixQ[ctr];
				break;
			/* 輸入若為運算元，則直接輸出 */
			default :
				printf("%c", infixQ[ctr]);
				break;
		}
	}
}

/*比較兩運算子優先權，若輸入運算子小於堆疊中運算子，則傳回值為1，否則為0 */
int compare(char stackO, char infixO)
{
	int indexS = 0, indexI = 0;
	while(stackPriority[indexS] != stackO)
		indexS++;
	while(infixPriority[indexI] != infixO)
		indexI++;
	return indexS/2 >= indexI/2 ? 1 : 0;
}

