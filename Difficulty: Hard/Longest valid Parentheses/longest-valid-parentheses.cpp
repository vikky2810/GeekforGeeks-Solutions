//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxLength(string str) {
        // code here
        stack<int> s;
    s.push(-1);  // Base index to calculate lengths
    int maxLength = 0;

    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '(') {
            s.push(i);  // Push the index of the '('
        } else {
            s.pop();  // Pop the last '(' or base index
            if(s.empty()) {
                s.push(i);  // Push the index of unmatched ')'
            } else {
                maxLength = max(maxLength, i - s.top());
            }
        }
    }

    return maxLength;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
// } Driver Code Ends