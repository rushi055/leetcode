class Solution {
public:
    vector<int> ans;
    int row;
    int col;

    bool isValid(vector<vector<int>>& matrix, int val, int r, int c) {
        for (int i = 0; i < col; i++) {
            if (val > matrix[r][i]) {
                return false;
            }
        }
        for (int i = 0; i < row; i++) {
            if (val < matrix[i][c]) {
                return false;
            }
        }
        return true;
    }

    void solve(vector<vector<int>>& matrix, vector<int>& ans) {
        row = matrix.size();
        col = matrix[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (isValid(matrix, matrix[i][j], i, j)) {
                    ans.push_back(matrix[i][j]);
                }
            }
        }
    }

    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        solve(matrix, ans);
        return ans;
    }
};
