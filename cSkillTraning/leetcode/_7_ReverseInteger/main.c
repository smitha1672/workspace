#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
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

void xorSwap (char *x, char *y) {
  if (x != y) {
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
  }
}

int reverse(int x)
{
  int ret = 0;
  long int value = 0;
  int n = 0;
  int i  = 0, r = 0, l = 0;
  char *strNumberArray = (char*)calloc(12, sizeof(char));
  char *pEnd = NULL;

  if (strNumberArray) {
    memset(strNumberArray, 0, 12);
    sprintf(strNumberArray, "%d", x);
    n = strlen(strNumberArray);
  }

  if (x > 0) {
    r = n - 1;
    l = 0;
    for (i = 0; i < n/2; i++) {
      xorSwap(strNumberArray+(l++), strNumberArray+(r--));
    }
  } else if (x < 0) {
    r = n - 1;
    l = 1;
    for (i = 0; i < n/2; i++) {
      xorSwap(strNumberArray+(l++), strNumberArray+(r--));
    }
  } else {
    return ret;
  }

  value = strtol(strNumberArray, NULL, 10);
  if (value >= INT_MIN && value <= INT_MAX)
    ret = (int)value;
  else
    ret = 0;
  if (strNumberArray)
    free(strNumberArray);
  return ret;
}

void main (void)
{
  int input = -2147483648;
  int output = 0;

  printf(LEETCODE_LINK);
  printf("input: %d\n", input);
  output = reverse(input);
  printf("out: %d\n", output);

}
