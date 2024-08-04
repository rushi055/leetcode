class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = i; j < n; j++) {
                count += nums[j];
                ans.push_back(count);
            }
        }
        sort(begin(ans), end(ans));
        int result = 0;
        int mod = 1e9 + 7;

        for (int i = left - 1; i < right; i++) {
            result = (result + ans[i]) % mod;
        }
        return result;
    }
};