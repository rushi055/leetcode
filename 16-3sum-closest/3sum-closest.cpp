class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        int mini = INT_MAX;

        for (int k = 0; k < n - 2; k++) {
            int i = k + 1;
            int j = n - 1;
            while (i < j) {
                int z = nums[k] + nums[i] + nums[j];
                if (mini > abs(target - z)) {
                    mini = abs(target - z);
                    ans = z;
                }

                if (z > target) {
                    j--;
                } else if (z < target) {
                    i++;
                } else {
                    return z;
                }
            }
        }
        return ans;
    }
};