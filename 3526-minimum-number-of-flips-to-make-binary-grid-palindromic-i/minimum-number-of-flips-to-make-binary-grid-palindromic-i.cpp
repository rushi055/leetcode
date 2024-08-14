class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int rowFlip = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                if (grid[i][j] != grid[i][n - j - 1]) {
                    rowFlip++;
                }
            }
        }
        int colFlip = 0;
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m / 2; ++i) {
                if (grid[i][j] != grid[m - i - 1][j]) {
                    colFlip++;
                }
            }
        }

        return min(rowFlip, colFlip);
    }
};