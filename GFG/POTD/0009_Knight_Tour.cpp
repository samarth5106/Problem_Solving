
class Solution {
public:
    int N;
    vector<pair<int, int>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    bool isSafe(int x, int y, vector<vector<int>>& board) {
        return (x >= 0 && y >= 0 && x < N && y < N && board[x][y] == -1);
    }

    bool solve(int x, int y, int moveCount, vector<vector<int>>& board) {
        if (moveCount == N * N) return true;

        for (auto [dx, dy] : moves) {
            int nx = x + dx;
            int ny = y + dy;

            if (isSafe(nx, ny, board)) {
                board[nx][ny] = moveCount;
                if (solve(nx, ny, moveCount + 1, board)) return true;
                board[nx][ny] = -1; // backtrack
            }
        }

        return false;
    }

    vector<vector<int>> knightTour(int n) {
        N = n;
        vector<vector<int>> board(n, vector<int>(n, -1));
        board[0][0] = 0; // Start from top-left

        if (solve(0, 0, 1, board)) {
            return board;
        }
        return {}; // No solution
    }
};
