//  Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive),
//  prove that at least one duplicate number must exist. Assume that there is only one duplicate number,
//  find the duplicate one.
//
//  Example 1:
//
//  Input: [1,3,4,2,2]
//  Output: 2
//  Example 2:
//
//  Input: [3,1,3,4,2]
//  Output: 3
//  Note:
//
//  You must not modify the array (assume the array is read only).
//  You must use only constant, O(1) extra space.
//  Your runtime complexity should be less than O(n2).
//  There is only one duplicate number in the array, but it could be repeated more than once.

//  class Solution {
//  public:
//      int
//      findDuplicate(vector<int>& nums)
//      {
//      }
//  };

#include <vector>
#include <iostream>

#include <stdio.h>

using namespace std;

// Author: Huahua
// Running time: 8 ms
class Solution {
public:
    int
    findDuplicate(vector<int>& nums)
    {
        int l = 1;
        int r = nums.size();
        while (l < r) {
            int m = (r - l) / 2 + l;
            int count = 0; // len(nums <= m)
            for (int num : nums) {
                if (num <= m) {
                    ++count;
                }
            }
            if (count <= m)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
};


int
main(void)
{
    //Solution s;
    vector<int>nums = {3,1,3,4,2};
    Solution s;
    cout << s.findDuplicate(nums) << endl;
    return 0;
}
