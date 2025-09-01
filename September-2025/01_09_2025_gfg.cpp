#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int sumOfModes(vector<int>& arr, int k) {
        int n = arr.size();
        int sum = 0;
        for (int i = 0; i <= n - k; ++i) {
            vector<int> subarray;
            for (int j = 0; j < k; ++j) {
                subarray.push_back(arr[i + j]);
            }

            unordered_map<int, int> counts;
            int max_freq = 0;
            int mode = -1;

            for (int num : subarray) {
                counts[num]++;
                if (counts[num] > max_freq) {
                    max_freq = counts[num];
                    mode = num;
                } else if (counts[num] == max_freq && num < mode) {
                    mode = num;
                }
            }
            sum += mode;
        }
        return sum;
    }
};