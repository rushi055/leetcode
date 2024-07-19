const auto init = []() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    return nullptr;
}();
class Solution {
public:
    set<vector<int>> ans;
    vector<int> temp;

    void solve(vector<int>& candidates, int target, int sum, int start) {
        if (sum == target) {
            ans.insert(temp);
            return;
        }
        if (sum > target) {
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target) {
                continue;
            }
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            sum += candidates[i];
            temp.push_back(candidates[i]);
            solve(candidates, target, sum, i + 1);
            sum -= candidates[i];
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0, 0);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
