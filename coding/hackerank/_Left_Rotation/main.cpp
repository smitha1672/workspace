#include <bits/stdc++.h>
#include <vector>

using namespace std;

// new idx = (i+(n - d))%n;
vector<int> rotateLeft(int d, vector<int> arr)
{
    vector<int> rot(arr.size(), -1);

    for (int i = 0; i < arr.size(); i++) {
        int j = ((i + (arr.size()-d)) % arr.size());

        rot[j] = arr[i];

    }

    return rot;
}

int main(void)
{
    int d = 4;
    vector<int> arr{1, 2, 3, 4, 5};
    vector<int> new_arr(arr.size(), -1);

    new_arr = rotateLeft(d, arr);

    for (int i = 0; i < new_arr.size(); i++)
        cout << new_arr[i] << " ";
    cout << "\n";


    return 0;
}

