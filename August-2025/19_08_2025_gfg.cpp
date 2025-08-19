#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, -1);
        vector<int> stack;

        for (int i = 0; i < n; ++i) {
            while (!stack.empty() && arr[stack.back()] > arr[i]) {
                result[stack.back()] = i;
                stack.pop_back();
            }
            stack.push_back(i);
        }

        return result;
    }
};