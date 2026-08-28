class Solution {
private:
    void dfs(vector<vector<int>>& heights, int r, int c, int prevHeight, vector<vector<bool>>& ocean) {
        int m = heights.size();
        int n = heights[0].size();
        
        if (r < 0 || r >= m || c < 0 || c >= n || ocean[r][c] || heights[r][c] < prevHeight) {
            return;
        }
        
        ocean[r][c] = true;
        
        dfs(heights, r + 1, c, heights[r][c], ocean);
        dfs(heights, r - 1, c, heights[r][c], ocean);
        dfs(heights, r, c + 1, heights[r][c], ocean);
        dfs(heights, r, c - 1, heights[r][c], ocean);
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        if (heights.empty() || heights[0].empty()) return result;
        
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
        for (int c = 0; c < n; ++c) {
            dfs(heights, 0, c, heights[0][c], pacific);
            dfs(heights, m - 1, c, heights[m - 1][c], atlantic);
        }
        
        for (int r = 0; r < m; ++r) {
            dfs(heights, r, 0, heights[r][0], pacific);
            dfs(heights, r, n - 1, heights[r][n - 1], atlantic);
        }
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }
        
        return result;
    }
};
