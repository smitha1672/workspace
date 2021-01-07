//  Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.
//
//  Example:
//
//  Input: s = 7, nums = [2,3,1,2,4,3]
//  Output: 2
//
//  Explanation: the subarray [4,3] has the minimal length under the problem constraint.
//  Follow up:
//  If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).

//  class Solution {
//  public:
//      int
//      minSubArrayLen(int s, vector<int>& nums)
//      {
//      }
//  };

#include <vector>
#include <algorithm>
#include <climits> // INT_MAX
#include <iostream>

using namespace std;

// https://github.com/grandyang/leetcode/issues/209
// O(n)
class Solution1 {
public:
    int
    minSubArrayLen(int s, vector<int>& nums)
    {
        if (nums.empty()) return 0;
        int left = 0, right = 0, sum = 0, len = nums.size(), res = len + 1;
        while (right < len) {
            while (sum < s && right < len)
                sum += nums[right++];
            while (sum >= s) {
                res = min(res, right - left);
                sum -= nums[left++];
            }
        }
        return res == len + 1 ? 0 : res;
    }
};

// https://github.com/grandyang/leetcode/issues/209
class Solution2 {
public:
    int
    minSubArrayLen(int s, vector<int>& nums)
    {
        int res = INT_MAX, left = 0, sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            while (left <= i && sum >= s) {
                res = min(res, i - left + 1);
                sum -= nums[left++];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};

// https://github.com/grandyang/leetcode/issues/209
// O(nlgn)
class Solution3 {
public:
    int
    minSubArrayLen(int s, vector<int>& nums)
    {
        int len = nums.size(), sums[len + 1] = {0}, res = len + 1;
        for (int i = 1; i < len + 1; ++i) sums[i] = sums[i - 1] + nums[i - 1];
        for (int i = 0; i < len + 1; ++i) {
            int right = searchRight(i + 1, len, sums[i] + s, sums);
            if (right == len + 1) break;
            if (res > right - i) res = right - i;
        }
        return res == len + 1 ? 0 : res;
    }
    int
    searchRight(int left, int right, int key, int sums[])
    {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (sums[mid] >= key) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};

// https://github.com/grandyang/leetcode/issues/209
class Solution4 {
public:
    int
    minSubArrayLen(int s, vector<int>& nums)
    {
        int res = INT_MAX, n = nums.size();
        vector<int> sums(n + 1, 0);
        for (int i = 1; i < n + 1; ++i) sums[i] = sums[i - 1] + nums[i - 1];
        for (int i = 0; i < n; ++i) {
            int left = i + 1, right = n, t = sums[i] + s;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (sums[mid] < t) left = mid + 1;
                else right = mid - 1;
            }
            if (left == n + 1) break;
            res = min(res, left - i);
        }
        return res == INT_MAX ? 0 : res;
    }
};

int
main(void)
{
    vector<int>nums{2,3,1,2,4,3};
    Solution4 s;
    cout << s.minSubArrayLen(7, nums) << endl;
    return 0;
}
