//Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also
//in arr1.
//
//Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2.
//Elements that don't appear in arr2 should be placed at the end of arr1 in ascending order.
//
//Example 1:
//
//    Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
//    Output: [2,2,2,1,4,3,3,9,6,7,19]
//
//Constraints:
//
//  arr1.length, arr2.length <= 1000
//  0 <= arr1[i], arr2[i] <= 1000
//  Each arr2[i] is distinct.
//  Each arr2[i] is in arr1.

//class Solution {
//public:
//    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2)
//    {
//
//    }
//};


#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

// https://leetcode.com/problems/relative-sort-array/discuss/334908/chinesec-1122-map-tong-ji-on-jin-xing-xiang-dui-wei-zhi-pai-xu
// Time complexity: O(n)
// Space complexity:
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2)
    {
        map<int, int> m;
        for (auto v: arr1)
            m[v]++;

        for (auto iter = m.begin(); iter != m.end(); iter ++)
            cout << "m1 ("<< iter->first << ", " << iter->second << ")\n";

        vector<int> ans;
        for (auto v: arr2) {
            auto it = m.find(v);
            while (it->second > 0) {
                ans.push_back(v);
                it->second--;
            }
        }

        for (auto iter = m.begin(); iter != m.end(); iter ++)
            cout << "m2 ("<< iter->first << ", " << iter->second << ")\n";

        for (auto p: m) {
            while (p.second > 0) {
                ans.push_back(p.first);
                p.second--;
            }
        }
        return ans;
    }
};

int
main(void)
{
    int i = 0;
    Solution s;
    vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19}, arr2 = {2, 1, 4, 3, 9, 6};
    vector<int> result;
    result = s.relativeSortArray(arr1, arr2);
    printf("result =");
    for (i = 0 ; i < result.size(); i++)
        printf(" %d ", result[i]);
    printf("\n");
    return 0;
}
