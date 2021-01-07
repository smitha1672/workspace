//  Given an array of citations sorted in ascending order (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.
//
//  According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."
//
//  Example:
//
//  Input: citations = [0,1,3,5,6]
//  Output: 3
//  Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each of them had
//  received 0, 1, 3, 5, 6 citations respectively.
//  Since the researcher has 3 papers with at least 3 citations each and the remaining
//  two with no more than 3 citations each, her h-index is 3.
//  Note:
//
//  If there are several possible values for h, the maximum one is taken as the h-index.
//
//  Follow up:
//
//  This is a follow up problem to H-Index, where citations is now guaranteed to be sorted in ascending order.
//  Could you solve it in logarithmic time complexity?

//  class Solution {
//  public:
//      int
//      hIndex(vector<int>& citations)
//      {
//      }
//  };

#include <vector>
#include <iostream>

using namespace std;

// Author: Huahua
// Running time: 9 ms
class Solution2 {
public:
    int
    hIndex(vector<int>& citations)
    {
        int n = citations.size();
        int l = 0;
        int r = n;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (citations[n - m - 1] <= m)
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};

//https://www.cnblogs.com/grandyang/p/4782695.html
class Solution1 {
public:
    int
    hIndex(vector<int>& citations)
    {
        int len = citations.size(), left = 0, right = len - 1;
        while (left <= right) {
            int mid = left+(right-left)/2;
            if (citations[mid] == len - mid) return len - mid;
            else if (citations[mid] > len - mid) right = mid - 1;
            else left = mid + 1;
        }
        return len - left;
    }
};

int
main(void)
{
    vector<int>citations_{0, 1, 3, 5, 6};
    Solution1 s1;
    cout << s1.hIndex(citations_) << endl;
    Solution2 s2;
    cout << s2.hIndex(citations_) << endl;

    return 0;
}
