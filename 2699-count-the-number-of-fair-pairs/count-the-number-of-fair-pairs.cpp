#include <algorithm>
#include <vector>

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(begin(nums), end(nums));
        long long ans = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            int low =
                lower_bound(begin(nums) + i + 1, end(nums), lower - nums[i]) -
                begin(nums);
            int high =
                upper_bound(begin(nums) + i + 1, end(nums), upper - nums[i]) -
                begin(nums);
            ans += 1LL * (high - low);
        }
        return ans;
    }
};