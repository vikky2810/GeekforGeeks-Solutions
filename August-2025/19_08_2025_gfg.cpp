#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> ans(n, -1);
        for(int i = 0; i < n; i++){
            for(int j = n - 1; j > i; j--){
                if(arr[j] < arr[i]){
                    ans[i] = j;
                    break;
                }
            }
        }
        return ans;
    }
};