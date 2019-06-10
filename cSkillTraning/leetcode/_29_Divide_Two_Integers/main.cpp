//  Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
//
//  Return the quotient after dividing dividend by divisor.
//
//  The integer division should truncate toward zero.
//
//  Example 1:
//
//  Input: dividend = 10, divisor = 3
//  Output: 3
//  Example 2:
//
//  Input: dividend = 7, divisor = -3
//  Output: -2
//  Note:
//
//  1. Both dividend and divisor will be 32-bit signed integers.
//  2. The divisor will never be 0.
//  3. Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1].
//      For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.

//  class Solution {
//  public:
//      int
//      divide(int dividend, int divisor)
//      {
//      }
//  };

#include <climits>
#include <cstdlib>
#include <iostream>

using namespace std;

class Solution1 {
public:
    int
    divide(int dividend, int divisor)
    {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
        long long m = abs((long long)dividend), n = abs((long long)divisor), res = 0;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        if (n == 1) return sign == 1 ? m : -m;
        while (m >= n) {
            long long t = n, p = 1;
            while (m >= (t << 1)) {
                t <<= 1;
                p <<= 1;
            }
            res += p;
            m -= t;
        }
        return sign == 1 ? res : -res;
    }
};

class Solution2 {
public:
    int
    divide(int dividend, int divisor)
    {
        long long m = abs((long long)dividend), n = abs((long long)divisor), res = 0;
        if (m < n) return 0;
        while (m >= n) {
            long long t = n, p = 1;
            while (m > (t << 1)) {
                t <<= 1;
                p <<= 1;
            }
            res += p;
            m -= t;
        }
        if ((dividend < 0) ^ (divisor < 0)) res = -res;
        return res > INT_MAX ? INT_MAX : res;
    }
};

class Solution3 {
public:
    int
    divide(int dividend, int divisor)
    {
        long long res = 0;
        long long m = abs((long long)dividend), n = abs((long long)divisor);
        if (m < n) return 0;
        long long t = n, p = 1;
        while (m > (t << 1)) {
            t <<= 1;
            p <<= 1;
        }
        res += p + divide(m - t, n);
        if ((dividend < 0) ^ (divisor < 0)) res = -res;
        return res > INT_MAX ? INT_MAX : res;
    }
};

int
main(void)
{
    Solution3 s;
    cout << s.divide(10, 3) << endl;
    return 0;
}
