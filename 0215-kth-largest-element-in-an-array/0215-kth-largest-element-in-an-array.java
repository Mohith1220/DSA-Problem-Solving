class Solution {
    public int findKthLargest(int[] nums, int k) {
        int minValue = Integer.MAX_VALUE;
        int maxValue = Integer.MIN_VALUE;

        for (int num : nums) {
            minValue = Math.min(minValue, num);
            maxValue = Math.max(maxValue, num);
        }

        int[] count = new int[maxValue - minValue + 1];

        for (int num : nums) {
            count[num - minValue]++;
        }
        for (int i = count.length - 1; i >= 0; i--) {
            k -= count[i];
            if (k <= 0) {
                return i + minValue;
            }
        }

        return -1;
    }
}