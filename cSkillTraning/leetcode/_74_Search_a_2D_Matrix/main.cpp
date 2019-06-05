//  Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//
//  Integers in each row are sorted from left to right.
//  The first integer of each row is greater than the last integer of the previous row.
//  Example 1:
//
//  Input:
//  matrix = [
//      [1,   3,  5,  7],
//      [10, 11, 16, 20],
//      [23, 30, 34, 50]
//  ]
//  target = 3
//  Output: true
//  Example 2:
//
//  Input:
//  matrix = [
//      [1,   3,  5,  7],
//      [10, 11, 16, 20],
//      [23, 30, 34, 50]
//  ]
//  target = 13
//  Output: false

//  class Solution {
//  public:
//      bool
//      searchMatrix(vector<vector<int>>& matrix, int target)
//      {
//      }
//  };

#include <vector>
#include <iostream>

using namespace std;

//https://www.cnblogs.com/grandyang/p/4323301.html
// Two binary search
class Solution1 {
public:
    bool
    searchMatrix(vector<vector<int> >& matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty()) return false;
        if (target < matrix[0][0] || target > matrix.back().back()) return false;
        int left = 0, right = matrix.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[mid][0] == target) return true;
            else if (matrix[mid][0] < target) left = mid + 1;
            else right = mid - 1;
        }
        int tmp = right;
        left = 0;
        right = matrix[tmp].size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[tmp][mid] == target) return true;
            else if (matrix[tmp][mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};

// One binary search
class Solution2 {
public:
    bool
    searchMatrix(vector<vector<int> >& matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty()) return false;
        if (target < matrix[0][0] || target > matrix.back().back()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[mid / n][mid % n] == target) return true;
            else if (matrix[mid / n][mid % n] < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};

//https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-74-search-a-2d-matrix/
class Solution3 {
public:
    bool
    searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if (matrix.empty()) return false;
        int l = 0;
        int r = matrix.size() * matrix[0].size();
        const int cols = matrix[0].size();
        while (l < r) {
            const int m = l + (r - l) / 2;
            if (matrix[m / cols][m % cols] == target)
                return true;
            else if (matrix[m / cols][m % cols] > target)
                r = m;
            else
                l = m + 1;
        }
        return false;
    }
};

int
main(void)
{
    vector<vector<int>>matrix = {
        {1,   3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    Solution2 s2;
    cout << s2.searchMatrix(matrix, 3) << endl;
    return 0;
}
