#define FOR(i, n) for (int i = 0; i < n; ++i)

class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();

        if (i < 0 || i >= m || j >= n) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int moves = 0;
        if (i > 0 && j + 1 < n && grid[i][j] < grid[i - 1][j + 1]) {
            moves = max(moves, 1 + solve(grid, i - 1, j + 1));
        }
        if (j + 1 < n && grid[i][j] < grid[i][j + 1]) {
            moves = max(moves, 1 + solve(grid, i, j + 1));
        }
        if (i + 1 < m && j + 1 < n && grid[i][j] < grid[i + 1][j + 1]) {
            moves = max(moves, 1 + solve(grid, i + 1, j + 1));
        }

        dp[i][j] = moves;
        return moves;
    }

    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        dp = vector<vector<int>>(m, vector<int>(n, -1));
        int z = 0;

        FOR(i, m) {
            z = max(z, solve(grid, i, 0));
        }

        return z;
    }
};
