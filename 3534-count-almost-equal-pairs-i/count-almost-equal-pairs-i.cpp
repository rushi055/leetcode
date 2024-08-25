class Solution {
public:
    int countPairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int mini, maxi;
                if (nums[i] > nums[j]) {
                    mini = nums[j];
                    maxi = nums[i];
                } else if (nums[i] == nums[j]) {
                    count++;
                    continue;
                } else {
                    mini = nums[i];
                    maxi = nums[j];
                }

                // string num1 = to_string(mini);
                string num2 = to_string(maxi);
                for (int a = 0; a < num2.length(); a++) {
                    for (int b = a + 1; b < num2.length(); b++) {
                        swap(num2[a], num2[b]);
                        if (mini == stoi(num2)) {
                            count++;
                        }
                        swap(num2[a], num2[b]);
                    }
                }
            }
        }
        return count;
    }
};