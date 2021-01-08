#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int (*fptr) (vector<vector<int>>& accounts);

int my_maximumWealth(vector<vector<int>>& accounts)
{
    int richest = 0;

    for (int m = 0; m < accounts.size(); m++) {
        int sum = 0;
        sum = accumulate(accounts[m].begin(),
                accounts[m].end(),
                0);
        richest = max(richest, sum);
    }

    return richest;
}

int maximumWealth(vector<vector<int>>& accounts)
{
    int richest = 0;
    for (auto m : accounts) {
        int sum = 0;
        for (auto n : m)
            sum += n;
        richest = max(richest, sum);
    }
    return richest;
}


int main(void)
{
    vector<vector<int>> accounts = {
        {1, 5},
        {7, 3},
        {3, 5}
    };

    fptr = my_maximumWealth;
    cout << fptr(accounts) << endl;

    fptr = maximumWealth;
    cout << fptr(accounts) << endl;

    return 0;
}

