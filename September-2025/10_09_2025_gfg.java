class Solution {
    public String largestSwap(String s) {
        int n = s.length();
        int maxIndex = -1;
        char[] arr = s.toCharArray();
        for (int i = 0; i < n - 1; i++) {
            char current = arr[i];
            char maxChar = current;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] >= maxChar) {
                    maxChar = arr[j];
                    maxIndex = j;
                }
            }
            if (maxChar > current) {
                char temp = arr[i];
                arr[i] = arr[maxIndex];
                arr[maxIndex] = temp;
                return new String(arr);
            }
        }
        return s;
    }
}