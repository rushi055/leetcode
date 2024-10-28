#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long check_lcm(vector<int>& nums, int j) {
        long long g = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (i == j)
                continue;
            g = lcm(g, nums[i]);
            if (g > 1e18)
                return g;
        }
        return g;
    }

    long long check_gcd(vector<int>& nums, int j) {
        long long g = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == j)
                continue;
            g = gcd(g, nums[i]);
        }
        return g;
    }

    long long maxScore(vector<int>& nums) {
        long long ans = LLONG_MIN;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < 2; j++) {
                if (j == 0) {
                    long long gcd_val = check_gcd(nums, n );
                    long long lcm_val = check_lcm(nums, n);
                    long long maxans = gcd_val * lcm_val;
                    ans = max(maxans, ans);
                } else {
                    long long gcd_val = check_gcd(nums, i);
                    long long lcm_val = check_lcm(nums, i);
                    long long maxans = gcd_val * lcm_val;
                    ans = max(maxans, ans);
                }
            }
        }
        return ans;
    }
};
