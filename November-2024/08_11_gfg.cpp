#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        int count = 1;
        string repeated_s1 = s1;
        while (repeated_s1.length() < s2.length()) {
            repeated_s1 += s1;
            count++;
        }
        if (repeated_s1.find(s2) != string::npos) {
            return count;
        }
        repeated_s1 += s1;
        count++;
        if (repeated_s1.find(s2) != string::npos) {
            return count;
        }

        return -1;
    }
};


int main() {
 	int t ; cin >> t;
 	Solution s;
 	while(t--)
 	{
 		string str1;
		cin >> str1;
		string str2;
		cin >> str2;
		
		int result = s.minRepeats(str1,str2);
		
		cout << "Result : " << result << endl;
	}
    return 0;
}
