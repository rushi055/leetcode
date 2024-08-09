class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int row, int col, int size) {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += grid[row][col + i];
        }

        // Check each row
        for (int i = 1; i < size; i++) {
            int rowSum = 0;
            for (int j = 0; j < size; j++) {
                rowSum += grid[row + i][col + j];
            }
            if (rowSum != sum)
                return false;
        }

        // Check each column
        for (int i = 0; i < size; i++) {
            int colSum = 0;
            for (int j = 0; j < size; j++) {
                colSum += grid[row + j][col + i];
            }
            if (colSum != sum)
                return false;
        }

        // Check main diagonal
        int diagSum1 = 0;
        for (int i = 0; i < size; i++) {
            diagSum1 += grid[row + i][col + i];
        }
        if (diagSum1 != sum)
            return false;

        // Check anti-diagonal
        int diagSum2 = 0;
        for (int i = 0; i < size; i++) {
            diagSum2 += grid[row + i][col + size - 1 - i];
        }
        if (diagSum2 != sum)
            return false;

        return true;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxSize = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 2; i + k <= n && j + k <= m; ++k) {
                    if (isValid(grid, i, j, k)) {
                        maxSize = max(maxSize, k);
                    }
                }
            }
        }

        return maxSize;
    }
};
