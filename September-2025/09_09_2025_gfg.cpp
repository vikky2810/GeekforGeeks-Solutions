#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
        sort(mices.begin(), mices.end());
        sort(holes.begin(), holes.end());
        int max_time = 0;
        for (int i = 0; i < mices.size(); ++i) {
            max_time = max(max_time, abs(mices[i] - holes[i]));
        }
        return max_time;
    }
};