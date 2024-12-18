class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        int row[4] = {-1, 0, 1, 0};
        int col[4] = {0, 1, 0, -1};
        int ans = 0;

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            ans = max(ans, t);

            for (int i = 0; i < 4; i++) {
                int rd = r + row[i];
                int cd = c + col[i];
                if (rd >= 0 && rd < n && cd >= 0 && cd < m &&
                    grid[rd][cd] == 1 && vis[rd][cd] == 0) {
                    q.push({{rd, cd}, t + 1});
                    vis[rd][cd] = 1;
                    grid[rd][cd] = 2;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return ans;
    }
};
