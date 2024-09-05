class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i, int k, int n, vector<int>& v) {
        if (v.size() == k) {
            ans.push_back(v);
            return;
        }

        for (int j = i; j <= n; j++) {
            v.push_back(j);
            solve(j + 1, k, n, v);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        solve(1, k, n, v);

        return ans;
    }
};