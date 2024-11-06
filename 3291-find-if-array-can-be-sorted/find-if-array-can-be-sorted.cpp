//__builtin_popcount(nums[i]);

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            bool k = false;
            for (int j = 0; j < n - i - 1; j++) {
                int m = __builtin_popcount(nums[j]);
                int v = __builtin_popcount(nums[j + 1]);
                if (nums[j] > nums[j + 1] && m == v) {
                    swap(nums[j], nums[j + 1]);
                    k = true;
                } else if (nums[j] > nums[j + 1] && m != v) {
                    return false;
                }
            }
        }

        return true;
    }
};