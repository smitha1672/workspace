#include <algorithm>
#include <vector>
#include <iostream>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val);
};

int
Solution::removeElement(std::vector<int>& nums, int val)
{
    int pos = 0;
    for (int i=0; i<nums.size(); i++) {
        if (nums[i] != val)
            nums[pos++] = nums[i];
    }
    return pos;
}

int
main(void)
{
    std::vector<int> nums = {2};
    int val = 3;
    Solution s;
    s.removeElement(nums, val);
    for (int i = 0; i < nums.size(); i++)
        std::cout << nums[i] << std::endl;
    return 0;
}
