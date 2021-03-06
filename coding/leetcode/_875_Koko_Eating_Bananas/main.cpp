//  Koko loves to eat bananas.  There are N piles of bananas, the i-th pile has piles[i] bananas.  The guards have gone and will come back in H hours.
//
//  Koko can decide her bananas-per-hour eating speed of K.  Each hour, she chooses some pile of bananas, and eats K bananas from that pile.
//  If the pile has less than K bananas, she eats all of them instead, and won't eat any more bananas during this hour.
//
//  Koko likes to eat slowly, but still wants to finish eating all the bananas before the guards come back.
//
//  Return the minimum integer K such that she can eat all the bananas within H hours.
//
//  Example 1:
//  Input: piles = [3,6,7,11], H = 8
//  Output: 4
//
//  Example 2:
//  Input: piles = [30,11,23,4,20], H = 5
//  Output: 30
//
//  Example 3:
//  Input: piles = [30,11,23,4,20], H = 6
//  Output: 23
//
//
//  Note:
//
//  # 1 <= piles.length <= 10^4
//  # piles.length <= H <= 10^9
//  # 1 <= piles[i] <= 10^9

//  class Solution {
//  public:
//      int
//      minEatingSpeed(vector<int>& piles, int H)
//      {
//      }
//  };

#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int
    minEatingSpeed(vector<int>& piles, int H)
    {
        int left = 1, right = *max_element(begin(piles), end(piles)) + 1;
        while (left < right) {
            int mid = left + (right - left) / 2, cnt = 0;
            /*
                比如 K=4，那么假如有3个香蕉，需要1个小时，有4香蕉，还是1个小时，有5个香蕉，就需要两个小时，
                如果将三种情况融合为一个式子呢，就是用吃速加上香蕉个数减去1，再除以吃速即可，即 (pile+mid-1)/mid，
            */
            for (int pile : piles) cnt += (pile + mid - 1) / mid;
            if (cnt > H) left = mid + 1;
            else right = mid;
        }
        return right;
    }
};

int
main(void)
{
    vector<int>piles = {3, 6, 7, 11};
    int H = 8;
    Solution s;
    cout << s.minEatingSpeed(piles, H) << endl;
    return 0;
}
