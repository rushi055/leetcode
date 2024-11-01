class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& memo) {
        int n = grid.size();
        int m = grid[0].size();

        if (i == n - 1 && j == m - 1) {
            return grid[i][j];
        }

        if (i >= n || j >= m) {
            return INT_MAX;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        int right = solve(i, j + 1, grid, memo);
        int down = solve(i + 1, j, grid, memo);

        return memo[i][j] = grid[i][j] + min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> memo(n, vector<int>(m, -1));
        return solve(0, 0, grid, memo);
    }
};
