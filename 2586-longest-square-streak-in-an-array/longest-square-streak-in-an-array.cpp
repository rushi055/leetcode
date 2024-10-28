#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int maxNum = 1e5;
        vector<int> dp(maxNum + 1, 0);
        unordered_set<int> numSet(nums.begin(), nums.end());
        int ans = -1;

        sort(nums.begin(), nums.end());

        for (int num : nums) {
            dp[num] = max(dp[num], 1);
            long long square = (long long)num * num;

            if (square <= maxNum && numSet.count(square)) {
                dp[square] = max(dp[square], dp[num] + 1);
                ans = max(ans, dp[square]);
            }
        }

        return ans > 1 ? ans : -1;
    }
};
