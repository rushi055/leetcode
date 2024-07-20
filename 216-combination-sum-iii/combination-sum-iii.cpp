class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;

    void solve(vector<int>& nums, int k, int n, int sum, int start) {
        if (temp.size() == k && sum == n) {
            result.push_back(temp);
            return;
        }
        if (temp.size() > k || sum > n) {
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            sum += nums[i];
            temp.push_back(nums[i]);
            solve(nums, k, n, sum, i + 1);
            sum -= nums[i];
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        for (int i = 1; i < 10; i++) {
            nums.push_back(i);
        }
        solve(nums, k, n, 0, 0);
        return result;
    }
};
