class Solution {
public:
    set<vector<int>> st;

    void solve(vector<int>& nums, int i, vector<int>& temp) {
        if (i >= nums.size()) {
            sort(temp.begin(), temp.end());
            st.insert(temp);
            return;
        }

        temp.push_back(nums[i]);
        solve(nums, i + 1, temp);
        temp.pop_back();
        solve(nums, i + 1, temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(), nums.end());
        solve(nums, 0, temp);
        vector<vector<int>> result(st.begin(), st.end());
        return result;
    }
};