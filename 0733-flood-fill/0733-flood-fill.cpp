class Solution {
private:
    void dfs(vector<vector<int>>& img, int r, int c, int oldC, int newC) {
        if (r < 0 || r >= img.size() || c < 0 || c >= img[0].size() || img[r][c] != oldC) {
            return;
        }
        img[r][c] = newC;
        dfs(img, r - 1, c, oldC, newC);
        dfs(img, r + 1, c, oldC, newC);
        dfs(img, r, c - 1, oldC, newC);
        dfs(img, r, c + 1, oldC, newC);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int color) {
        int oldC = img[sr][sc];
        if (oldC != color) {
            dfs(img, sr, sc, oldC, color);
        }
        return img;
    }
};
