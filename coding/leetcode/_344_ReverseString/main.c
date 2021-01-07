/*
link: https://leetcode.com/problems/reverse-string/description/

Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
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

char* reverseString(char* s) {
  size_t len = strlen(s)-1;
  int j = 0, k = 0;

  k = len;
  while (j < k)
    charXorSwap(&s[j++], &s[k--]);
  return s;
}

void main(void)
{
  char s[40] = "";

  reverseString(s);
  printf("%s\n", s);
}

