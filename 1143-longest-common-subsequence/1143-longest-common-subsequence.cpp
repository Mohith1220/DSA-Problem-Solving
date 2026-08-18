class Solution {
public:
    int solve(string &a, string &b, int i, int j,
              vector<vector<int>>& dp) {

        if(i == a.size() || j == b.size())
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];
        if(a[i] == b[j])
            return dp[i][j] = 1 + solve(a, b, i + 1, j + 1, dp);
        return dp[i][j] = max(
            solve(a, b, i + 1, j, dp),
            solve(a, b, i, j + 1, dp)
        );
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(text1, text2, 0, 0, dp);
    }
};