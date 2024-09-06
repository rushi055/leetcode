// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle){
//         int n=triangle.size();
//         vector<vector<int>> dp(n,vector<int>(n,0));
//         for(int i=n-1;i>=0;i--)
//         {
//             for(int j=0;j<i+1;j++)
//             {
//                 if(i==n-1)
//                 {
//                     dp[i][j]=triangle[i][j];
//                 }else
//                 {
//                     dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
//                 }
//             }
//         }
//         return dp[0][0];
//     }
// };
class Solution {
public:
    // Memoization table (dp) initialized with -1 to indicate uncomputed
    
    vector<vector<int>> dp;

    int solve(vector<vector<int>>& triangle, int i, int j) {
        if (i == triangle.size()) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int down = solve(triangle, i + 1, j);
        int diagonal = solve(triangle, i + 1, j + 1);
        return dp[i][j] = triangle[i][j] + min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        dp.resize(n, vector<int>(n, -1));

        return solve(triangle, 0, 0);
    }
};
