class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        long long ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            pq.push(nums[i]);
        }
        while (k != 0) {
            int a = pq.top();
            ans += a;
            pq.pop();
            pq.push(ceil((double)a / 3));
            k--;
        }
        return ans;
    }
};