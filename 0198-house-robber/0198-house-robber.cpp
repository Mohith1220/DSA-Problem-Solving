class Solution {
public:

    // =====================================================
    // 1. RECURSION
    // Time: O(2^n)
    // Space: O(n)
    // =====================================================
    int recursion(vector<int>& nums, int i) {

        if (i >= nums.size())
            return 0;

        int rob = nums[i] + recursion(nums, i + 2);
        int skip = recursion(nums, i + 1);

        return max(rob, skip);
    }


    // =====================================================
    // 2. MEMOIZATION
    // Time: O(n)
    // Space: O(n)
    // =====================================================
    int memoization(vector<int>& nums, int i, vector<int>& dp) {

        if (i >= nums.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int rob = nums[i] + memoization(nums, i + 2, dp);
        int skip = memoization(nums, i + 1, dp);

        return dp[i] = max(rob, skip);
    }


    // =====================================================
    // 3. TABULATION
    // Time: O(n)
    // Space: O(n)
    // =====================================================
    int tabulation(vector<int>& nums) {

        int n = nums.size();

        if (n == 0)
            return 0;

        if (n == 1)
            return nums[0];

        vector<int> dp(n + 1, 0);

        dp[0] = 0;
        dp[1] = nums[0];

        for (int i = 2; i <= n; i++) {

            // Skip current house
            int skip = dp[i - 1];

            // Rob current house
            int rob = nums[i - 1] + dp[i - 2];

            dp[i] = max(skip, rob);
        }

        return dp[n];
    }


    // =====================================================
    // 4. SPACE OPTIMIZED DP
    // Time: O(n)
    // Space: O(1)
    // =====================================================
    int optimizedDP(vector<int>& nums) {

        int prev2 = 0;
        int prev1 = 0;

        for (int money : nums) {

            // Skip current OR rob current
            int curr = max(prev1, prev2 + money);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }


    // =====================================================
    // LEETCODE FUNCTION
    // =====================================================
    int rob(vector<int>& nums) {

        // Choose ONE approach to return.
        
        // 1. Recursion
        // return recursion(nums, 0);

        // 2. Memoization
        // vector<int> dp(nums.size(), -1);
        // return memoization(nums, 0, dp);

        // 3. Tabulation
         return tabulation(nums);

        // 4. Space Optimized DP
       // return optimizedDP(nums);
    }
};