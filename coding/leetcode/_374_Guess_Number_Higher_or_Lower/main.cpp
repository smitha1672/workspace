//  We are playing the Guess Game. The game is as follows:
//
//  I pick a number from 1 to n. You have to guess which number I picked.
//
//  Every time you guess wrong, I'll tell you whether the number is higher or lower.
//
//  You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):
//
//  -1 : My number is lower
//   1 : My number is higher
//    0 : Congrats! You got it!
//    Example :
//
//    Input: n = 10, pick = 6
//    Output: 6

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0

#include <iostream>

int guess(int num);

class Solution {
public:
    int guessNumber(int n);
};

int
guess(int num)
{
    int pick = 6;
    if (num < pick) return 1;
    else if (num > pick) return -1;
    else return 0;
}

int
Solution::guessNumber(int n)
{
    if (guess(n) == 0) return n;
    int left = 1, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2, target = guess(mid);
        if (target == 0) return mid;
        else if (target == 1) left = mid;
        else right = mid;
    }
    return left;
}

int
main(void)
{
    Solution s;
    std::cout << s.guessNumber(10) << std::endl;
    return 0;
}