//  Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.
//
//  Example 1:
//
//  Input:
//  A: [1,2,3,2,1]
//  B: [3,2,1,4,7]
//  Output: 3
//  Explanation:
//  The repeated subarray with maximum length is [3, 2, 1].
//
//
//  Note:
//
//  1 <= len(A), len(B) <= 1000
//  0 <= A[i], B[i] < 100

//  class Solution {
//  public:
//      int
//      findLength(vector<int>& A, vector<int>& B)
//      {
//      }
//  };

//  Solution: DP
//  dp[i][j] := max length of (A[0:i], B[0:j])
//
//  dp[i][j] = dp[i – 1][j – 1] + 1 if A[i-1] == B[j-1] else 0
//
//  Time complexity: O(m*n)
//  Space complexity: O(m*n) -> O(n)

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int
    findLength(vector<int>& A, vector<int>& B)
    {
        int res = 0;
        vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j < dp[i].size(); ++j) {
                dp[i][j] = (A[i - 1] == B[j - 1]) ? dp[i - 1][j - 1] + 1 : 0;
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};

int
main(void)
{
    vector<int>A = {1,2,3,2,1};
    vector<int>B = {3,2,1,4,7};
    Solution s;
    cout << s.findLength(A, B);
    return 0;
}
