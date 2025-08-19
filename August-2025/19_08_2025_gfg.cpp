#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, -1);
        for (int i = 0; i < n; ++i) {
            for (int j = n - 1; j > i; --j) {
                if (arr[j] < arr[i]) {
                    result[i] = j;
                    break;
                }
            }
        }
        return result;
    }
};