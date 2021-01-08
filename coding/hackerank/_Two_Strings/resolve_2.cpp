#include <iostream>
#include <map>
#include <cstring>
#include <string>

using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2)
{
    string letters = "abcdefghijklmnopqrstuvwxyz";
    string s_out = "NO";

    for (int i = 0; i < letters.size(); i++) {
        if (s1.find(letters[i]) != string::npos && \
            s2.find(letters[i]) != string::npos) {
            s_out = "YES";
            break;
        }
    }

    return s_out;
}

int main(void)
{
    string s1 = "hi";
    string s2 = "world";
    cout << twoStrings(s1, s2) << endl;

    return 0;
}
