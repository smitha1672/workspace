//  Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//  (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
//
//  Find the minimum element.
//
//  You may assume no duplicate exists in the array.
//
//  Example 1:
//
//  Input: [3,4,5,1,2]
//  Output: 1
//  Example 2:
//
//  Input: [4,5,6,7,0,1,2]
//  Output: 0

//  class Solution {
//  public:
//      int
//      findMin(vector<int>& nums)
//      {
//      }
//  };

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// Author: Huahua
class Solution {
public:
    int
    findMin(vector<int>& num)
    {
        return findMin(num, 0, num.size()-1);
    }

private:
    int
    findMin(const vector<int>& num, int l, int r)
    {
        // Only 1 or 2 elements
        if (l+1 >= r) return min(num[l], num[r]);
        // Sorted
        if (num[l] < num[r]) return num[l];
        int mid = l + (r-l)/2;
        return min(findMin(num, l, mid-1), findMin(num, mid, r));
    }
};

int
main(void)
{
    vector<int>num = {3,4,5,1,2};
    Solution s;
    cout << s.findMin(num) << endl;
    return 0;
}
