class Solution {
public:
    int mini = INT_MAX;
    int solve(vector<vector<int>>& triangle, vector<vector<int>> &dp,vector<vector<bool>> &vis, int i, int j) {
        if(vis[i][j])
        {
            return dp[i][j];
        }
        vis[i][j]=1;
        if(i==triangle.size()-1)
        {
            return dp[i][j]=triangle[i][j];
        }
        int x=solve(triangle, dp,vis, i + 1, j),y=solve(triangle, dp,vis, i + 1, j + 1);
        return dp[i][j]=triangle[i][j]+min(x,y);
    }

    int minimumTotal(vector<vector<int>>& triangle){
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        vector<vector<bool>> vis(n,vector<bool>(n,0));
        return solve(triangle,dp,vis,0,0);
    }
};
