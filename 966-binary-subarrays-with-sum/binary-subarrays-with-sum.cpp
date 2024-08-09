class Solution {
public:
  
    int numSubarraysWithSum(vector<int>& nums, int goal) {
         unordered_map<int, int> sumCount;
        sumCount[0] = 1; 
        int currentSum = 0;
        int result = 0;

        for (int num : nums) {
            currentSum += num;

            
            if (sumCount.find(currentSum - goal) != sumCount.end()) {
                result += sumCount[currentSum - goal];
            }

            sumCount[currentSum]++;
        }

        return result;
    }
    
};
