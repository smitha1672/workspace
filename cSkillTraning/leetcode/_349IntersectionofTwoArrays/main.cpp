#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    set<int> inter1, inter2;
    vector<int> solution;
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        for(int i = 0; i < nums1.size(); i++)
            inter1.insert(nums1[i]);
        for (int i = 0; i < nums2.size(); i++) {
            if (inter1.find(nums2[i]) != inter1.end())
                inter2.insert(nums2[i]);
        }
        for(set<int>::iterator it = inter2.begin(); it != inter2.end(); it++)
            solution.push_back(*it);
        return solution;
    }
};

int main(void)
{
    int arr1[] = {1,2,2,1};
    vector<int>nums1(arr1, arr1+(sizeof(arr1)/sizeof(arr1[0])));
    int arr2[] = {2,2};
    vector<int>nums2(arr2, arr2+(sizeof(arr2)/sizeof(arr2[0])));
    Solution solution;
    vector<int>retvec;
    vector<int>::iterator it;
    retvec = solution.intersection(nums1, nums2);
    cout << "[";
    for (it = retvec.begin(); it != retvec.end(); it++)
        cout << *it;
    cout << "]" << endl;

    return 0;
}


