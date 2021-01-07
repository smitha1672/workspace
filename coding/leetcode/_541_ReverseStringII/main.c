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

void
reverse(int start, int end, char* s)
{
    char tmp;
    while (start < end) {
        tmp = s[end];
        s[end--] = s[start];
        s[start++] = tmp;
    }
}

char*
reverseStr(char* s, int k)
{
    size_t len = strlen(s);
    if (len <= k) {
        reverse(0, len-1, s);
        return s;
    }
    for (int i = 0; i < len; i += (2*k)) {
        if (i+(2*k) <= len)   /*at least 2k left*/
            reverse(i, i+k-1, s);
        else if ((len-i) >= k) { /*more than or equal to k left*/
            reverse(i, i+k-1, s);
            break;
        } else if ((len-i) < k) { /*less than k,reverse i to len-1*/
            reverse(i, i+k-1, s);
            break;
        }
    }
    return s;
}

#define ITEM 10000
void
main(void)
{
    char s[] = "abcdefg";
    int k = 2;
    char* t = NULL;
    reverseStr(s, k);
    printf("s: %s\n", s);
}

