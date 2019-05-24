//  Given a positive integer num, write a function which returns True if num is a perfect square else
//  False.
//
//  Note: Do not use any built-in library function such as sqrt.
//
//  Example 1:
//
//  Input: 16
//  Output: true
//  Example 2:
//
//  Input: 14
//  Output: false

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num);
};

bool
Solution:: isPerfectSquare(int num)
{
    long left = 0, right = num;
    while (left <= right) {
        long mid = left+(right-left)/2;
        long target = mid*mid;
        if (target == num)
            return true;
        else if (target < num)
            left = mid+1;
        else
            right = mid-1;
    }
    return false;
}

int
main(void)
{
    Solution s;
    cout << s.isPerfectSquare(14) << endl;
    return 0;
}
