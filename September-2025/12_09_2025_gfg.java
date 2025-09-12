import java.util.Arrays;

class Solution {
    public int getMinDiff(int[] arr, int k) {
        int n = arr.length;
        Arrays.sort(arr);

        int ans = arr[n - 1] - arr[0];

        int smallest = arr[0] + k;
        int largest = arr[n - 1] - k;

        for (int i = 0; i < n - 1; i++) {
            int add = arr[i] + k;
            int subtract = arr[i + 1] - k;

            if (subtract >= 0) {
                smallest = Math.min(smallest, subtract);
                largest = Math.max(largest, add);
                ans = Math.min(ans, largest - smallest);
            }
        }
        return ans;
    }
}