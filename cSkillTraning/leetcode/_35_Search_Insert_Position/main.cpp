//  Given a sorted array and a target value, return the index if the target is found. If not, return the
//  index where it would be if it were inserted in order.
//
//  You may assume no duplicates in the array.
//
//  Example 1:
//
//  Input: [1,3,5,6], 5
//  Output: 2
//  Example 2:
//
//  Input: [1,3,5,6], 2
//  Output: 1
//  Example 3:
//
//  Input: [1,3,5,6], 7
//  Output: 4
//  Example 4:
//
//  Input: [1,3,5,6], 0
//  Output: 0

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target);
};

int
binarysearch(vector<int>& nums, int target)
{
    int left = 0, right = nums.size()-1;
    int mid = 0;
    while (left <= right) {
        mid = left+(right-left)/2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid+1;
        else
            right = mid-1;
    }
    return left;
}

int
Solution::searchInsert(vector<int>& nums, int target)
{
    if (nums.size() == 0) return nums.size();
    return binarysearch(nums, target);
}

int
main(void)
{
    int in[] = {1, 3, 5, 6};
    int target = 2;
    vector<int>nums(in, in+(sizeof(in)/sizeof(in[0])));
    Solution s;
    cout << s.searchInsert(nums, target) << endl;
    return 0;
}
