#include <vector>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <numeric>

using namespace std;

struct Player {
    int score;
    string name;
};

class Checker {
public:
    // complete this method
    static int comparator(Player a, Player b)
    {
        if (a.score > b.score)
            return 1;
        else if (a.score == b.score) {
            /*the means alphabetical order a string > b string*/
            return (a.name > b.name)? -1:0;
            //return (a.name.compare(b.name) > 0)? -1: 0;
        }
        return -1;
    }
};

bool compare(Player a, Player b)
{
    if (Checker::comparator(a, b) == -1)
        return false;
    return true;
}

int main(void)
{
    vector<struct Player> players{
        {1, "a"},
        {3, "amy"},
        {3, "david"},
        {4, "d"},
    };

    for (auto i: players)
        cout << i.score << ' ' << i.name << '\n';
    cout << '\n';

    sort(players.begin(), players.end(), compare);

    cout << "after sort" << '\n';
    for (auto i: players)
        cout << i.score << ' ' << i.name << '\n';
    cout << '\n';

    return 0;
}
