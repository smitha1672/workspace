//  Given an unsorted array of integers, find the length of longest increasing subsequence.
//
//  Example:
//
//  Input: [10,9,2,5,3,7,101,18]
//  Output: 4
//  Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
//
//  Note:
//
//  There may be more than one LIS combination, it is only necessary for you to return the length.
//  Your algorithm should run in O(n2) complexity.
//  Follow up: Could you improve it to O(n log n) time complexity?

//  class Solution {
//  public:
//      int
//      lengthOfLIS(vector<int>& nums)
//      {
//      }
//  };

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution1 {
public:
    int
    lengthOfLIS(vector<int>& nums)
    {
        vector<int> dp(nums.size(), 1);
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

class Solution2 {
public:
    int
    lengthOfLIS(vector<int>& nums)
    {
        if (nums.empty()) return 0;
        vector<int> ends{nums[0]};
        for (auto a : nums) {
            if (a < ends[0]) ends[0] = a;
            else if (a > ends.back()) ends.push_back(a);
            else {
                int left = 0, right = ends.size();
                while (left < right) {
                    int mid = left + (right - left) / 2;
                    if (ends[mid] < a) left = mid + 1;
                    else right = mid;
                }
                ends[right] = a;
            }
        }
        return ends.size();
    }
};

class Solution3 {
public:
    int
    lengthOfLIS(vector<int>& nums)
    {
        vector<int> dp;
        for (int i = 0; i < nums.size(); ++i) {
            int left = 0, right = dp.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (dp[mid] < nums[i]) left = mid + 1;
                else right = mid;
            }
            if (right >= dp.size()) dp.push_back(nums[i]);
            else dp[right] = nums[i];
        }
        return dp.size();
    }
};

class Solution4 {
public:
    int
    lengthOfLIS(vector<int>& nums)
    {
        vector<int> v;
        for (auto a : nums) {
            auto it = lower_bound(v.begin(), v.end(), a);
            if (it == v.end()) v.push_back(a);
            else *it = a;
        }
        return v.size();
    }
};

class Solution5 {
public:
    int
    lengthOfLIS(vector<int>& nums)
    {
        vector<int> v;
        for (auto a : nums) {
            if (find(v.begin(), v.end(), a) != v.end()) continue;
            auto it = upper_bound(v.begin(), v.end(), a);
            if (it == v.end()) v.push_back(a);
            else *it = a;
        }
        return v.size();
    }
};

int
main(void)
{
    vector<int> nums_{10,9,2,5,3,7,101,18};
    Solution1 s2;
    cout << s2.lengthOfLIS(nums_) << endl;
    return 0;
}
