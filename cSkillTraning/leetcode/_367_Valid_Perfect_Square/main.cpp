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
