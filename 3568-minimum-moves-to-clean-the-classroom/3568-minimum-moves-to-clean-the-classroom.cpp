class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr, sc;
        vector<vector<int>> litterId(m, vector<int>(n, -1));

        int k = 0;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (classroom[r][c] == 'S') {
                    sr = r;
                    sc = c;
                } else if (classroom[r][c] == 'L') {
                    litterId[r][c] = k++;
                }
            }
        }

        int masks = 1 << k;
        int fullMask = masks - 1;

        vector<int8_t> best(m * n * masks, -1);

        auto encode = [&](int r, int c, int mask) {
            return ((r * n + c) * masks + mask);
        };

        struct State {
            int pos;
            int mask;
            int energy;
        };

        queue<State> q;

        best[encode(sr, sc, 0)] = energy;
        q.push({sr * n + sc, 0, energy});

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        int moves = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [pos, mask, e] = q.front();
                q.pop();

                if (mask == fullMask)
                    return moves;

                if (e == 0)
                    continue;

                int r = pos / n;
                int c = pos % n;

                for (int d = 0; d < 4; ++d) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n ||
                        classroom[nr][nc] == 'X')
                        continue;

                    int ne = e - 1;
                    int nmask = mask;

                    if (classroom[nr][nc] == 'L')
                        nmask |= 1 << litterId[nr][nc];

                    if (classroom[nr][nc] == 'R')
                        ne = energy;

                    int idx = encode(nr, nc, nmask);

                    if (ne <= best[idx])
                        continue;

                    best[idx] = ne;
                    q.push({nr * n + nc, nmask, ne});
                }
            }

            ++moves;
        }

        return -1;
    }
};
