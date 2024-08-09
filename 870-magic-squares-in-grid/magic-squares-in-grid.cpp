const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return nullptr;
}();

class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int row, int col) {
        vector<int> cnt(10,0);

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int k = grid[row + i][col + j];
                if (k < 1 || k > 9 || cnt[k] > 0) {
                    return false;
                }
                cnt[k]++;
            }
        }
        int sum = grid[row][col] + grid[row][col+1] + grid[row][col+2];
        for (int i = 0; i < 3; ++i) {
            if (grid[row + i][col] + grid[row + i][col + 1] + grid[row + i][col + 2] != sum) {
                return false;
            }
            if (grid[row][col + i] + grid[row + 1][col + i] + grid[row + 2][col + i] != sum) {
                return false;
            }
        }
        
        if (grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2] != sum) {
            return false;
        }
        if (grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col] != sum) {
            return false;
        }
        
        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid.size();//row
        int m = grid[0].size();//col

        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= m - 3; j++) {
                if (isValid(grid, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }
};