class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        int countOnes = accumulate(begin(nums), end(nums), 0);

        int i = 0;
        int j = 0;
        int currCount = 0;
        int maxCount = 0;

        while (j < 2 * n) {
            if (nums[j % n] == 1) {
                currCount++;
            }

            if (j - i + 1 > countOnes) {
                currCount -= nums[i % n];
                i++;
            }

            maxCount = max(maxCount, currCount);
            j++;
        }

        return countOnes - maxCount;
    }
};