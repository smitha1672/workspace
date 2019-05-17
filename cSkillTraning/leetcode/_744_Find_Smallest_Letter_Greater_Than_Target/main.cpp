//    Given a list of sorted characters letters containing only lowercase letters, and given a target
//    letter target, find the smallest element in the list that is larger than the given target.
//
//    Letters also wrap around. For example, if the target is target = 'z' and letters = ['a', 'b'], the
//    answer is 'a'.
//
//    Examples:
//    Input:
//    letters = ["c", "f", "j"]
//    target = "a"
//    Output: "c"
//
//    Input:
//    letters = ["c", "f", "j"]
//    target = "c"
//    Output: "f"
//
//    Input:
//    letters = ["c", "f", "j"]
//    target = "d"
//    Output: "f"
//
//    Input:
//    letters = ["c", "f", "j"]
//    target = "g"
//    Output: "j"
//
//    Input:
//    letters = ["c", "f", "j"]
//    target = "j"
//    Output: "c"
//
//    Input:
//    letters = ["c", "f", "j"]
//    target = "k"
//    Output: "c"
//    Note:
//    letters has a length in range [2, 10000].
//    letters consists of lowercase letters, and contains at least 2 unique letters.
//    target is a lowercase letter.

//  class Solution {
//  public:
//      char
//      nextGreatestLetter(vector<char>& letters, char target)
//      {
//      }
//  };


#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target);
};

char
Solution::nextGreatestLetter(vector<char>& letters, char target)
{
    int left = 0, right = letters.size()-1, mid = 0;
    if (target >= letters.back())
        return letters[0];
    while (left < right) {
        mid = left+(right-left)/2;
        if (letters[mid] <= target)
            left = mid+1;
        else
            right = mid;
    }
    return letters[right];
}

int
main(void)
{
    char in[] = {'c', 'f', 'j'};
    vector<char>letters(in, in+(sizeof(in)/sizeof(in[0])));
    char target = 'a';
    Solution s;
    cout << s.nextGreatestLetter(letters, target) << endl;
    return 0;
}

