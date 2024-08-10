class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n - 1; i++) {
            int left = i + 1, right = n - 1;
            int complement = target - nums[i];
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] < complement) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            count += (left - i - 1);
        }

        return count;
    }
};