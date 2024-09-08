class Solution {
public:
    typedef long long ll;
    long long findMaximumScore(vector<int>& nums) {
        int n = nums.size();
        ll ans = 0;
        int i = 0;
        for (int j = 0; j < n; j++) {
            if (nums[i] < nums[j]) {
                ans += (ll)(j - i) * (ll)nums[i];
                i = j;
            }
        }
        if (i != n - 1) {
            ans += (ll)((n - 1) - i) * (ll)nums[i];
        }

        return ans;
    }
};