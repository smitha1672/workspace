#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<int> runningSum(vector<int>& nums)
{
    vector<int> v_out(nums.size(), 0);

#if 0   /*my solution*/
    partial_sum(nums.begin(),
        (nums.begin() +  nums.size()),
        v_out.begin());
#endif
    for (int i = 1; i < nums.size(); i++)
        nums[i] = nums[i] + nums[i-1];
    v_out = nums;

    return v_out;
}

int main(void)
{
    vector<int> v_in = {1,2,3,4};
    vector<int> v_out = runningSum(v_in);

    for (const auto &e: v_out)
        cout << e << " ";
    cout << "\n";

    return 0;
}
