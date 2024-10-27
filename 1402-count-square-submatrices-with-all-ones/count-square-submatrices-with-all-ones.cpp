class Solution {
public:
    bool check(vector<vector<int>>& matrix, int i, int j, int k) {
        for (int x = i; x < i + k; x++) {
            for (int y = j; y < j + k; y++) {
                if (matrix[x][y] == 0) {
                    return false;
                }
            }
        }
        return true;
    }
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 1; i + k <= m && j + k <= n; k++) {
                    if (check(matrix, i, j, k)) {
                        count++; 
                    } else {
                        break; 
                    }
                }
            }
        }

        return count;
    }
};
