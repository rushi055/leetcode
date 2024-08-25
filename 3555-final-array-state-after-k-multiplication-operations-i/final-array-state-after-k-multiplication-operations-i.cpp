class Solution {
public:
    vector<int> solvemin(vector<int>& nums, int k, int multiplier) {
        int x = nums[0];
        int n = nums.size();
        int j = 0;
        if (k == 0) {
            return nums;
        }
        for (int i = 1; i < n; i++) {
            if (nums[i] < x) {
                j = i;
                x = nums[i];
            }
        }
        nums[j] = nums[j] * multiplier;
        solvemin(nums, k - 1, multiplier);
        return nums;
    }
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        return solvemin(nums, k, multiplier);
    }
};