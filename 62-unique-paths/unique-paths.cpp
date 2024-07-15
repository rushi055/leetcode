
// TLE
// class Solution {
// public:
//     bool isSafe(int i, int j, int m, int n) {
//         return i >= 0 && i < m && j >= 0 && j < n;
//     }

//     void paths(int i, int j, int m, int n, int& count) {

//         if (!isSafe(i, j, m, n)) {
//             return;
//         }
//         if (i == m - 1 && j == n - 1) {
//             count++;
//             return;
//         }
//         paths(i + 1, j, m, n, count);

//         paths(i, j + 1, m, n, count);
//     }

//     int uniquePaths(int m, int n) {
//         int count = 0;
//         paths(0, 0, m, n, count);
//         return count;
//     }
// };
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return paths(0, 0, m, n, memo);
    }
    
    int paths(int i, int j, int m, int n, vector<vector<int>> &memo) {

        if (i >= m || j >= n) {
            return 0;
        }
        if (i == m - 1 && j == n - 1) {
            return 1;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        
        int right = paths(i, j + 1, m, n, memo);
        int down = paths(i + 1, j, m, n, memo);
        
        memo[i][j] = right + down;
        
        return memo[i][j];
    }
};
