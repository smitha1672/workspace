//  You have a total of n coins that you want to form in a staircase shape, where every k-th row must
//  have exactly k coins.
//
//  Given n, find the total number of full staircase rows that can be formed.
//
//  n is a non-negative integer and fits within the range of a 32-bit signed integer.
//
//  Example 1:
//
//  n = 5
//
//  The coins can form the following rows:
//  ¤
//  ¤ ¤
//  ¤ ¤
//
//  Because the 3rd row is incomplete, we return 2.
//  Example 2:
//
//  n = 8
//
//  The coins can form the following rows:
//  ¤
//  ¤ ¤
//  ¤ ¤ ¤
//  ¤ ¤
//
//  Because the 4th row is incomplete, we return 3.

//  class Solution {
//      public:
//          int arrangeCoins(int n);
//  };

#include <math.h>
#include <iostream>

class Solution {
public:
    int arrangeCoins(int n);
};

int
Solution::arrangeCoins(int n)
{
    long left = 0, right = n;
    long mid = 0;
    if (n <= 1) return n;
    while (left < right) {
        mid = left+(right-left)/2;
        if (mid*(mid+1)/2 <= n)
            left = mid+1;
        else
            right = mid;
    }
    return left - 1;
}

int
main(void)
{
    Solution s;
    std::cout << sqrt(4) << std::endl;
    std::cout << s.arrangeCoins(8) << std::endl;
    return 0;
}
