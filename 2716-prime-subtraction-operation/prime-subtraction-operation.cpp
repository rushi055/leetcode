class Solution {
public:
    int check(vector<bool>& prime, int i) {
        int k = 0;
        for (int j = i + 1; j < prime.size(); j++) {
            if (prime[j]) {
                return j;
            }
        }
        return k;
    }
    bool primeSubOperation(vector<int>& nums) {
        vector<bool> prime(1000, true);
        prime[0] = prime[1] = false;

        for (int i = 2; i * i < 1000; i++) {
            if (prime[i]) {
                for (int j = i * i; j < 1000; j += i) {
                    prime[j] = false;
                }
            }
        }

        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i] <= nums[i - 1]) {
                int x = check(prime, nums[i - 1] - nums[i]);
                if (x == 0 || x >= nums[i - 1]) {
                    return false;
                } else {
                    nums[i - 1] = nums[i - 1] - x;
                }
            }
        }

        return true;
        ;
    }
};