import java.util.*;

class Solution {
    public int shortestPathBinaryMatrix(int[][] grid) {

        int n = grid.length;

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        int[] queue = new int[n * n];
        int front = 0, rear = 0;

        queue[rear++] = 0; // encode (0,0) as 0
        grid[0][0] = 1;    // use grid itself as visited

        int distance = 1;

        int[] dr = {-1,-1,-1,0,0,1,1,1};
        int[] dc = {-1,0,1,-1,1,-1,0,1};

        while (front < rear) {

            int size = rear - front;

            while (size-- > 0) {

                int pos = queue[front++];

                int r = pos / n;
                int c = pos % n;

                if (r == n - 1 && c == n - 1)
                    return distance;

                for (int k = 0; k < 8; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr >= 0 && nr < n &&
                        nc >= 0 && nc < n &&
                        grid[nr][nc] == 0) {

                        grid[nr][nc] = 1;
                        queue[rear++] = nr * n + nc;
                    }
                }
            }

            distance++;
        }

        return -1;
    }
}