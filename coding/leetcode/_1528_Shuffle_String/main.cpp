#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string restoreString(string s, vector<int>& indices)
{
    string sout = s;

    for (int i = 0; i < s.size(); i++)
        sout[indices[i]] = s[i];
    return sout;
}

int main(void)
{
    string str("codeleet");
    vector<int> indices{4, 5, 6, 7, 0, 2, 1, 3};

    restoreString(str, indices);
    return 0;
}


