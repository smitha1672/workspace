#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target);
};

int
Solution::search(vector<int>& nums, int target)
{
    int left = 0, right = nums.size()-1;
    int mid = 0;
    while (left <= right) {
        mid = left + (right - left)/2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int
main(void)
{
    Solution s;
    int arr[] = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    vector<int>nums(arr, arr+(sizeof(arr)/sizeof(arr[0])));
    cout << s.search(nums, target) << endl;
    return 0;
}
