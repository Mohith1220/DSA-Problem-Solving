class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.'));
        int targetMask = (1 << n) - 1;
        
        backtrack(0, n, 0, 0, 0, targetMask, board, solutions);
        return solutions;
    }

private:
    void backtrack(int row, int n, int cols, int diag1, int diag2, int targetMask,
                   vector<string>& board, vector<vector<string>>& solutions) {
        if (row == n) {
            solutions.push_back(board);
            return;
        }

        int availableSlots = targetMask & ~(cols | diag1 | diag2);

        while (availableSlots > 0) {
            int p = availableSlots & -availableSlots;
            availableSlots -= p;
            int col = __builtin_ctz(p); 

            board[row][col] = 'Q';

            backtrack(row + 1, n, 
                      cols | p, 
                      (diag1 | p) << 1, 
                      (diag2 | p) >> 1, 
                      targetMask, board, solutions);

            board[row][col] = '.';
        }
    }
};
