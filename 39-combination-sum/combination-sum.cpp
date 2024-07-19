class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(vector<int>& candidates, int target, int sum, int start) {
        if (sum == target) {
            ans.push_back(temp);
            return;
        }
        if (sum > target) {
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            sum += candidates[i];
            temp.push_back(candidates[i]);
            solve(candidates, target, sum, i);
            sum -= candidates[i];
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(candidates, target, 0, 0);
        return ans;
    }
};
