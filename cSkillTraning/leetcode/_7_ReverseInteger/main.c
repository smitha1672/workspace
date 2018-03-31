#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define LEETCODE_LINK "https://leetcode.com/problems/reverse-integer/description/\n"
/**
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:
Input: 123
Output:  321

Example 2:
Input: -123
Output: -321

Example 3:
Input: 120
Output: 21

Note:
Assume we are dealing with an environment which could only hold integers within the 32-bit signed integer range.
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

gcc -o main main.c -lm

int reverse(int x) {

}
*/

void printElement(int *array, int arraySize, int idx)
{
  int i = 0;

  printf("%d:", idx);
  for (i = 0; i < arraySize; i++) {
    printf(" %d", array[i]);
  }
  printf("\n");
}

void xorSwap (int *x, int *y) {
  if (x != y) {
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
  }
}

#if 0
int* convertNumberIntoArray(int number, int *retNumberArraySize)
{
  int n = log10(number) + 1;
  int i;
  int *numberArray = calloc(n, sizeof(int));

  if (!numberArray)
    return NULL;

  for (i = 0; i < n; ++i, number /= 10 ) {
    numberArray[i] = number % 10;
  }

  *retNumberArraySize= n;
  return numberArray;
}

int reverse(int x)
{
  int *pIntIntoArray = NULL;
  int retIntArraySize = 0;
  int i, l, r;
  int ret = 0;

  pIntIntoArray = convertNumberIntoArray(x, &retIntArraySize);
  if (pIntIntoArray) {
    r = retIntArraySize-1;
    l = 0;
    for (i = 0; i < (retIntArraySize/2); i++) { //reverse array
      printElement(pIntIntoArray, retIntArraySize, i);
      xorSwap(pIntIntoArray+(l++), pIntIntoArray+(r--));
    }

    r = 0;
    for (i = 0; i < retIntArraySize; i++)
      ret += pIntIntoArray[i]*(int)pow(10, i);

  }

  return ret;
}
#endif

int reverse(int x)
{
  int ret = 0;
  int n = log10(x) + 1 + 2; /*inlcude "\n"*/
  char *strNumberArray = (char*)calloc(n, sizeof(char));

    sprintf(strNumberArray, "%d", x);
    printf("array = %s\n", strNumberArray);

  return ret;
}

void main (void)
{
  int input = -1234;
  int output = 0;

  printf(LEETCODE_LINK);
  printf("input: %d\n", input);
  output = reverse(input);
  printf("out: %d\n", output);

}
