#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        sort(x.begin(), x.end(), greater<int>());
        sort(y.begin(), y.end(), greater<int>());

        int horizontal_segments = 1;
        int vertical_segments = 1;
        int x_index = 0;
        int y_index = 0;
        int total_cost = 0;

        while (x_index < x.size() && y_index < y.size()) {
            if (x[x_index] > y[y_index]) {
                total_cost += x[x_index] * horizontal_segments;
                vertical_segments++;
                x_index++;
            } else {
                total_cost += y[y_index] * vertical_segments;
                horizontal_segments++;
                y_index++;
            }
        }

        while (x_index < x.size()) {
            total_cost += x[x_index] * horizontal_segments;
            vertical_segments++;
            x_index++;
        }

        while (y_index < y.size()) {
            total_cost += y[y_index] * vertical_segments;
            horizontal_segments++;
            y_index++;
        }

        return total_cost;
    }
};