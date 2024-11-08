class Solution {
public:
    string intToBinary(int n) {
        if (n == 0)
            return "0";

        string binary = "";
        while (n > 0) {
            binary = (n % 2 == 0 ? "0" : "1") + binary;
            n /= 2;
        }
        return binary;
    }
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int maxxor = 0;
        int n = nums.size();
        for (int num : nums) {
            maxxor ^= num;
        }
        // vector<int> result(n);
        // for (int i = 0; i < n; i++) {
        //     string s = intToBinary(nums[i]);
        //     int z = 0;
        //     for (int j = s.length() - 1; j >= 0; j--) {
        //         if (s[j] == 0) {
        //             z += pow(2, s.length() - 1 - i);
        //         }
        //     }
        //     result[i]=z;
        //     maxxor ^= nums[n - 1];
        //     n--;
        //     nums.pop_back();
        // }
        vector<int> result(n);
        int maxMask = (1 << maximumBit) - 1;

        for (int i = 0; i < n; i++) {
            result[i] = maxxor ^ maxMask;
            maxxor ^= nums[n - 1 - i];
        }

        return result;
    }
};