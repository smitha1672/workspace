/*
link: https://leetcode.com/problems/reverse-string-ii/description/

Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string.

If there are less than k characters left, reverse all of them.

If there are less than 2k but greater than or equal to k characters,
then reverse the first k characters and left the other as original.

Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"

Restrictions:
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]

example:
0 1 2 3 4 5 6
a b c d e f g
b a c d f e g
*/

#include <stdio.h>
#include <string.h>

void charXorSwap(char *x, char *y)
{
  if (x != y) {
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
  }
}

char* reverseStr(char* s, int k)
{
  size_t len = strlen(s)-1;
  int i = 0, l = 0, r = 0;

  if (len < k) {
    r = len;
    while (l < r)
      charXorSwap(&s[l++], &s[r--]);
  }

  return s;
}

#define ITEM 10000
void main(void)
{
  char s[ITEM];
  int k = 0;
  char *t = NULL;

  puts("input k, string");
  while(scanf("%d %9999s", &k, s) == 2) {
    t = reverseStr(s, k);
    printf("%s\n", t);
  }
}

