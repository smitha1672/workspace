#include <iostream>
#include <map>
#include <cstring>
#include <string>

using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2)
{
    map<char, int> mp_s_max;
    string s_max, s_min;
    int score = 0;

    if (s1.length() > s2.length()) {
        s_max = s1;
        s_min = s2;
    } else {
        s_max = s2;
        s_min = s1;
    }

    for (int i = 0; i < s_max.length(); i++) {
        char k = *(s_max.c_str() + i);
        mp_s_max.insert(make_pair(k, 1));
    }

    for (int i = 0; i < s_min.length(); i++) {
        if (mp_s_max.find(*(s_min.c_str()+i)) != mp_s_max.end())
            score ++;
    }

    return (score > 0)? "YES": "NO";
}

int main(void)
{
    string s1 = "hi";
    string s2 = "world";
    cout << twoStrings(s1, s2) << endl;

    return 0;
}
