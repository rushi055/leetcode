class Solution {
public:
// Perform same approach as we use in 560. Subarray Sum Equals K
    int numberOfSubarrays(vector<int>& nums, int k) {
       unordered_map<int, int> sumCount;
        sumCount[0] = 1; 
        int currentSum = 0;
        int niceCount = 0;

        for (int num : nums) {
            // Convert odd numbers to 1 and even numbers to 0
            currentSum += (num % 2 == 0) ? 0 : 1;

            // Check if there's a subarray with the sum equal to (currentSum - k)
            if (sumCount.find(currentSum - k) != sumCount.end()) {
                niceCount += sumCount[currentSum - k];
            }

            // Record the frequency of the current cumulative sum
            sumCount[currentSum]++;
        }

        return niceCount;
    }
};

