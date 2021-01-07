//  Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
//
//  Your algorithm's runtime complexity must be in the order of O(log n).
//
//  If the target is not found in the array, return [-1, -1].
//
//  Example 1:
//
//  Input: nums = [5,7,7,8,8,10], target = 8
//  Output: [3,4]
//  Example 2:
//
//  Input: nums = [5,7,7,8,8,10], target = 6
//  Output: [-1,-1]

//  class Solution {
//  public:
//      vector<int>
//      searchRange(vector<int>& nums, int target)
//      {
//      }
//  };

#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

// https://github.com/grandyang/leetcode/issues/34
class Solution1 {
public:
    vector<int>
    searchRange(vector<int>& nums, int target)
    {
        int idx = search(nums, 0, nums.size() - 1, target);
        if (idx == -1) return {-1, -1};
        int left = idx, right = idx;
        while (left > 0 && nums[left - 1] == nums[idx]) --left;
        while (right < nums.size() - 1 && nums[right + 1] == nums[idx]) ++right;
        return {left, right};
    }
    int
    search(vector<int>& nums, int left, int right, int target)
    {
        if (left > right) return -1;
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) return search(nums, mid + 1, right, target);
        else return search(nums, left, mid - 1, target);
    }
};

// fail
class Solution2 {
public:
    vector<int>
    searchRange(vector<int>& nums, int target)
    {
        vector<int> res(2, -1);
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        if (nums[right] != target) return res;
        res[0] = right;
        right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) left = mid + 1;
            else right= mid;
        }
        res[1] = left - 1;
        return res;
    }
};

// https://blog.csdn.net/fuxuemingzhu/article/details/83273084
class Solution3 {
public:
    vector<int>
    searchRange(vector<int>& nums, int target)
    {
        auto low = lower_bound(nums.begin(), nums.end(), target);
        auto high = upper_bound(nums.begin(), nums.end(), target);
        if (low == high) return {-1, -1};
        return {low - nums.begin(), high - nums.begin() - 1};
    }
};

int
main(void)
{
    vector<int>nums;
    Solution3 s;
    vector<int>out = s.searchRange(nums, 8);
    for (int i = 0; i < out.size(); i++)
        cout << out[i] << endl;
    return 0;
}

