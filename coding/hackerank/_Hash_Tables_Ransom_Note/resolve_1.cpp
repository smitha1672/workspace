#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

void checkMagazine(vector<string> magazine, vector<string> note)
{
    map<string, int> mp_magazine;
    int score = 0;

     /*create magazine hash map*/
    for (int i = 0; i < magazine.size(); i++) {
        string k = magazine[i];
        if (mp_magazine.find(k) != mp_magazine.end())
            mp_magazine.at(k) ++;
        else
            mp_magazine.insert(make_pair(k, 1));
    }

    /*search hash table*/
    for (int i = 0; i < note.size(); i++) {
        string k = note[i];

        if (mp_magazine.find(k) != mp_magazine.end()) {
            if (mp_magazine.at(k)-- <= 0) {
                cout << "No";
                return;
            }
            score ++;
        } else {
            cout << "No" << endl;
            return;
        }
    }

    if (score > 0)
        cout << "Yes" << endl;
}

int main (void)
{
    vector<string> magazine = {"two", "times", "three", "is", "not", "four"};
    vector<string> note = {"give", "two", "one", "grand", "today"};

    checkMagazine(magazine, note);
    return 0;
}
