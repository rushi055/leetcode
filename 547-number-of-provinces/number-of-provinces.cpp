class Solution {
public:
    void dfs(int i, vector<int>&vis, vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vis[i] = 1;
        for (int j = 0; j < n; j++) {
            if (isConnected[i][j] == 1 && !vis[j]) {
                dfs(j, vis, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int n = isConnected.size();
        vector<int> vis(n,0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                count++;
                dfs(i, vis, isConnected);
            }
        }
        return count;
    }
};