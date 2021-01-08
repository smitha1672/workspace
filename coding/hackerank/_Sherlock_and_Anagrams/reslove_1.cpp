#if 0   // note
sherlock and anagrams

sliding window
k = sliding window size

s = abcd
n = s.size = 4
k = 1
i = 0, j = 0, 1, 2, 3, stemp = a, b, c, d

k = 2
i = 0, j = 0, 1, 2; stemp = ab, bc, cd

for (i = 0; i < s.size(); i++) {
    for (j = i; j <= a.size() - k; j++) {

    }

}
#endif

#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int sherlockAndAnagrams(string s)
{
    map<string, int> mp;
    int anagrams_pairs = 0;

    for (int i = 0; i < s.size(); i++) {
        for (int j = 1; (i + j -1) < s.size(); j++) {
            string str_k = s.substr(i, j);
            cout << i << "\t" << j << "\t";
            cout << str_k << "\t";
            sort(str_k.begin(), str_k.end());
            cout << str_k << endl;
            mp[str_k] ++;
        }
    }

    /*
        For example, if you had to calculate how many groups of 4 you can form out of 6 people,
        there is formula you can use. It does seem odd, but we will make it work.

        = n!/((n-r)! * r!)

        n represents the total number of people you have. So, n = 6 for this problem. r is the
        number of people in the group you want to form. So, r = 4 in our example.

        to simple
        = n*(n-1)/2; 2 means pairs in one group. n means how many pairs
    */

    cout << "MAP:\n";
    for (const auto &e: mp) {
        cout << e.first << "\t";
        cout << e.second << "\n";
        anagrams_pairs += e.second*(e.second-1)/2;
    }


    return anagrams_pairs;
}

int main(void)
{
    string s = "abba";

    cout << sherlockAndAnagrams(s) << endl;
    return 0;
}

