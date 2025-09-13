import java.util.Arrays;

class Solution {
    public static int minCost(int n, int m, int[] x, int[] y) {
        Arrays.sort(x);
        Arrays.sort(y);

        int horizontalCuts = 1;
        int verticalCuts = 1;
        int cost = 0;

        int i = x.length - 1;
        int j = y.length - 1;

        while (i >= 0 || j >= 0) {
            if (i >= 0 && (j < 0 || x[i] >= y[j])) {
                cost += x[i] * horizontalCuts;
                verticalCuts++;
                i--;
            } else {
                cost += y[j] * verticalCuts;
                horizontalCuts++;
                j--;
            }
        }

        return cost;
    }
}