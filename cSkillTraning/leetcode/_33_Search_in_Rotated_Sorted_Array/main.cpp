//  Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//  (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
//
//  You are given a target value to search. If found in the array return its index, otherwise return -1.
//
//  You may assume no duplicate exists in the array.
//
//  Your algorithm's runtime complexity must be in the order of O(log n).
//
//  Example 1:
//
//  Input: nums = [4,5,6,7,0,1,2], target = 0
//  Output: 4
//
//  Example 2:
//
//  Input: nums = [4,5,6,7,0,1,2], target = 3
//  Output: -1

//  class Solution {
//  public:
//      int
//      search(vector<int>& nums, int target)
//      {
//      }
//  };

#include <vector>
#include <iostream>

using namespace std;

// https://www.cnblogs.com/grandyang/p/4325648.html
class Solution1 {
public:
    int
    search(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < nums[right]) {
                if (nums[mid] < target && nums[right] >= target) left = mid + 1;
                else right = mid - 1;
            } else {
                if (nums[left] <= target && nums[mid] > target) right = mid - 1;
                else left = mid + 1;
            }
        }
        return -1;
    }
};

// https://www.cnblogs.com/grandyang/p/4325648.html
class Solution2 {
public:
    int
    search(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] >= nums[left]) {
                if (nums[left] <= target && nums[mid] > target) right = mid - 1;
                else left = mid + 1;
            } else {
                if (nums[mid] < target && nums[right] >= target) left = mid + 1;
                else right = mid - 1;
            }
        }
        return -1;
    }
};

int
main(void)
{
    vector<int>nums={4,5,6,7,0,1,2};
    Solution1 s;
    cout << s.search(nums, 0) << endl;
    return 0;
}
