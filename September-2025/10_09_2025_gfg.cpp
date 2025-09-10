#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string largestSwap(string &s) {
        int n = s.length();
        int idx1 = -1, idx2 = -1;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (s[j] > s[i]) {
                    idx1 = i;
                    idx2 = j;
                }
            }
        }

        if (idx1 == -1) return s;

        char maxChar = s[idx1 + 1];
        int maxIdx = idx1 + 1;
        for(int i = idx1 + 1; i < n; i++) {
            if(s[i] >= maxChar) {
                maxChar = s[i];
                maxIdx = i;
            }
        }
        
        for (int i = 0; i < idx1; i++) {
            for (int j = idx1; j < n; j++){
                if (s[j] > s[i]){
                    idx1 = i;
                    break;
                }
            }
            if(idx1 != i) break;
        }

        maxChar = '0';
        maxIdx = -1;

        for(int i = idx1 + 1; i < n; i++) {
            if(s[i] > s[idx1]) {
                if(s[i] >= maxChar) {
                    maxChar = s[i];
                    maxIdx = i;
                }
            }
        }
        

        if(maxIdx == -1) return s;
        
        swap(s[idx1], s[maxIdx]);
        return s;
    }
};