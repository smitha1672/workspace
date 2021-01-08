#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<int> matchingStrings(vector<string> strings, vector<string> queries)
{
    vector<int> v_out;
    map<string, int> m_hash;

    /*O(q)*/
    for (int q = 0; q < strings.size(); q++) {
        string s_key = strings[q];

        if (m_hash.find(s_key) != m_hash.end())
            m_hash.at(s_key) ++;  // value ++
        else
            m_hash.insert(pair<string, int>(s_key, 1));
    }

    //for (auto itr = m_hash.begin(); itr != m_hash.end(); itr ++) {
    //    cout << itr->first << ":" << itr->second << "\n";
    //}

    /*O(n)*/
    for (int n = 0; n < queries.size(); n++) {
        string query = queries[n];

        if (m_hash.find(query) != m_hash.end())
            v_out.push_back(m_hash.at(query));
        else
            v_out.push_back(0);
    }

    /*O(n + q)*/
    return v_out;
}



int main (void)
{
    vector<string> strings = {"aba", "baba", "aba", "xzxb"};
    vector<string> queries = {"aba", "xzxb", "ab"};
    vector<int> out;

    out = matchingStrings(strings, queries);
    for (int i = 0; i < out.size(); i++)
        cout << out[i] << "\n";


    return 0;
}
