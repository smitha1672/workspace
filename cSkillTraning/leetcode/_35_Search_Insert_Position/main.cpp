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
    return -1;
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
