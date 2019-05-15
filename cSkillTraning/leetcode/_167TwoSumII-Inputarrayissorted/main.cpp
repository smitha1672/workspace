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
