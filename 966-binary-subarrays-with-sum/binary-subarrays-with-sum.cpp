class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;
        int sum = 0, i = 0, j = 0, count = 0;

        while (j < nums.size()) {
            sum += nums[j];
            while (sum > goal) {
                sum -= nums[i];
                i++;
            }
            count += j - i + 1;
            j++;
        }

        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};
