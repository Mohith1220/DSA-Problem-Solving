import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums == null || nums.length == 0) {
            return new int[0];
        }

        int n = nums.length;
        int[] ans = new int[n - k + 1];
        PriorityQueue<int[]> maxHeap = new PriorityQueue<>((a, b) -> b[0] - a[0]);

        for (int i = 0; i < k; i++) {
            maxHeap.offer(new int[]{nums[i], i});
        }
        ans[0] = maxHeap.peek()[0];

        int idx = 1;
        for (int i = k; i < n; i++) {
            maxHeap.offer(new int[]{nums[i], i});

            while (maxHeap.peek()[1] <= i - k) {
                maxHeap.poll();
            }

            ans[idx++] = maxHeap.peek()[0];
        }

        return ans;
    }
}
