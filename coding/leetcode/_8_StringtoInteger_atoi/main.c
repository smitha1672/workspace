#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#define LEETCODE_LINK "https://leetcode.com/problems/string-to-integer-atoi/description/\n"
/**
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Requirements for atoi:

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

gcc -o main main.c -lm

int myAtoi(char* str) {
}

a next challenge:
https://leetcode.com/problems/valid-number/description/
*/

int
myAtoi(char* str)
{
    long result = 0;
    int sign = 1;
    //discard the first sequence of whitespace characters.
    while (isspace(*str))
        str++;
    if ((*str == '+') || (*str == '-')) {
        sign = (*str == '+') ? 1:0;
        str++;
    }
    if (!isdigit(*str))
        return result;
    while (isdigit(*str) && (result <= INT_MAX)) {
        result = result * 10 + *str - '0' + 0;
        str++;
    }
    if (result > INT_MAX)
        return ((sign == 1) ? INT_MAX : INT_MIN);
    return ((sign == 1)? result : -result);
}

void
main (void)
{
    char input[12] = "1534236469";
    int output = 0;
    printf(LEETCODE_LINK);
    printf("input: %s\n", input);
    output = myAtoi(input);
    printf("out: %d\n", output);
}
