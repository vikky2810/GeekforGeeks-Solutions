import java.util.HashMap;
import java.util.Map;

class Solution {
    public int sumOfModes(int[] arr, int k) {
        int sum = 0;
        for (int i = 0; i <= arr.length - k; i++) {
            int mode = findMode(arr, i, k);
            sum += mode;
        }
        return sum;
    }

    private int findMode(int[] arr, int start, int k) {
        Map<Integer, Integer> frequencyMap = new HashMap<>();
        int mode = -1;
        int maxFrequency = 0;

        for (int i = start; i < start + k; i++) {
            int num = arr[i];
            frequencyMap.put(num, frequencyMap.getOrDefault(num, 0) + 1);
            int frequency = frequencyMap.get(num);

            if (frequency > maxFrequency) {
                maxFrequency = frequency;
                mode = num;
            } else if (frequency == maxFrequency) {
                if (num < mode || mode == -1) {
                    mode = num;
                }
            }
        }

        return mode;
    }
}