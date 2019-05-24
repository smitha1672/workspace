//  Given two arrays, write a function to compute their intersection.
//
//  Example 1:
//
//  Input: nums1 = [1,2,2,1], nums2 = [2,2]
//  Output: [2,2]
//  Example 2:
//
//  Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//  Output: [4,9]
//  Note:
//
//  Each element in the result should appear as many times as it shows in both arrays.
//  The result can be in any order.
//  Follow up:
//
//  What if the given array is already sorted? How would you optimize your algorithm?
//  What if nums1's size is small compared to nums2's size? Which algorithm is better?
//  What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load
//  all elements into the memory at once?

#include <algorithm>
#include <vector>
#include <iostream>

class Solution { // O(NlogN + MlogM)
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2);
};

std::vector<int>
Solution::intersect(std::vector<int>& nums1, std::vector<int>& nums2)
{
    std::sort(nums1.begin(), nums1.end());//we sort both vectors in order to intersect
    std::sort(nums2.begin(), nums2.end());//them later in O(N + M), where N = nums1.size()
    std::vector<int> solution;                                          //M = nums2.size()
    int index = 0;
    bool finished = false;
    for (int i = 0; i < nums1.size() && !finished; i++) {
        while (index < nums2.size() && nums1[i] > nums2[index]) //we skip over the
            index++;//smaller elements in nums2
        if (index == nums2.size()) //we have reached the end of nums2 so we have no more
            finished = true;//elements to add to the intersection
        else if (nums1[i] == nums2[index]) { //we found a common element
            solution.push_back(nums1[i]);
            index++;
        }
    }
    return solution;
}

int
main(void)
{
    int _nums1[] = {1,2,2,1}, _nums2[] = {2,2};
    std::vector<int>nums1(_nums1, _nums1+(sizeof(_nums1)/sizeof(_nums1[0])));
    std::vector<int>nums2(_nums2, _nums2+(sizeof(_nums2)/sizeof(_nums2[0])));
    Solution s;
    std::vector<int>out;
    out = s.intersect(nums1, nums2);
    for (std::vector<int>::iterator it=out.begin(); it != out.end(); ++it)
        std::cout << *(it) << ",";
    std::cout << std::endl;
    return 0;
}
