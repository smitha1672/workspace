#include <iostream>
#include <vector>
#include <map>

using namespace std;

int minimumSwaps(vector<int> arr)
{
    int minimumSwapsCnt = 0;
    vector<bool> isVisted(arr.size()+1, false);
    map<int, int> map_hash;

    for (int i = 1; i < isVisted.size(); i++)
        map_hash.insert(make_pair(i, arr[i-1]));

    for (int k = 1; k <= map_hash.size(); k++) {
        int nextNode;
        if (isVisted[k] == false) {
            isVisted[k] = true;

            if (map_hash.at(k) == k)
                continue;
            else {
                int c = map_hash.at(k);

                while (!isVisted[c]) {
                    isVisted[c] = true;
                    nextNode = map_hash.at(c);
                    c = nextNode;
                    ++ minimumSwapsCnt;
                }
            }
        }
    }

    return minimumSwapsCnt;
}

#if 0
// non-consecutive distinct integrs
// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr)
{
    int minimumSwapsCnt = 0;
    int minloc;

    for (int i = 0; i < arr.size()-1 ; i++) {
        minloc = i;
        for (int j = i; j < arr.size(); j++) {
            if (arr[j] < arr[minloc])
                minloc = j;
        }

        if (minloc != i) {
            swap(arr[i], arr[minloc]);
            minimumSwapsCnt ++;
        }
    }

    return minimumSwapsCnt;
}
#endif

int main(void)
{
    vector<int> arr = {1, 4, 3, 2};
    int minimumSwapsCnt = minimumSwaps(arr);

    cout << minimumSwapsCnt << endl;
    return 0;
}
