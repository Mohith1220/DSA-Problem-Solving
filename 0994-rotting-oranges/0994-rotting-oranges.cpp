class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        // Put all rotten oranges into queue
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                if (grid[r][c] == 2) {
                    q.push({r, c});
                }
                else if (grid[r][c] == 1) {
                    fresh++;
                }
            }
        }

        int minutes = 0;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty() && fresh > 0) {

            int size = q.size();

            // One BFS level = one minute
            for (int i = 0; i < size; i++) {

                int r = q.front().first;
                int c = q.front().second;

                q.pop();

                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr >= 0 && nr < m &&
                        nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {

                        grid[nr][nc] = 2;

                        fresh--;

                        q.push({nr, nc});
                    }
                }
            }

            minutes++;
        }

        if (fresh > 0)
            return -1;

        return minutes;
    }
};