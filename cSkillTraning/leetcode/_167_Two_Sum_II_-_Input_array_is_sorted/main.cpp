//  Given an array of integers that is already sorted in ascending order, find two numbers such that
//  they add up to a specific target number.
//
//  The function twoSum should return indices of the two numbers such that they add up to the target,
//  where index1 must be less than index2.
//
//  Note:
//
//  Your returned answers (both index1 and index2) are not zero-based.
//  You may assume that each input would have exactly one solution and you may not use the same element
//  twice.
//  Example:
//
//  Input: numbers = [2,7,11,15], target = 9
//  Output: [1,2]
//  Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.

#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int>
    twoSum(vector<int>& numbers, int target)
    {
        vector<int> solution;
        int low = 0, high = numbers.size()-1;
        while(low < high) {
            if (numbers[low] + numbers[high] == target) {
                solution.push_back(low+1);
                solution.push_back(high+1);
                return solution;
            } else {
                (numbers[low] + numbers[high] > target)? high--: low++;
            }
        }
        return solution;
    }
};

int main(void) {
    int arr[] = {2,7,11,15};
    vector<int> numbers(arr, arr+(sizeof(arr)/sizeof(arr[0])));
    int target = 9;
    Solution s;
    vector<int> retvect;
    retvect = s.twoSum(numbers, target);
    for (vector<int>::iterator it = retvect.begin(); it != retvect.end(); it++)
        cout << *it << " ";
    cout << endl;
    return 0;
}
