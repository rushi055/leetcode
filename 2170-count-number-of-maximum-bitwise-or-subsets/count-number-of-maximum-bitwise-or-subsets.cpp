// all possible subarray
// pair to store <greater_val,cnt>p
// value > p.first then cnt =1;
// if val == p.first ,cnt++;

class Solution {
public:
    pair<int, int> p;
    int maxor = 1;
    int cnt = 0;

    void solve(vector<int>& nums, int idx, int result) {

        // if (idx == nums.size() - 1) {
        //     int ori = v[0];
        //     for (int i = 1; i < v.size(); i++) {
        //         ori |= v[i];
        //     }
        //     if (ori > maxor) {
        //         cnt = 1;
        //         maxor = ori ;
        //     }

        //     return;
        // }
        // v.push_back(nums[idx]);
        // solve(nums, v, idx + 1, result);
        // v.pop_back();
        // solve(nums, v, idx + 1, result);

        if (idx == nums.size()) {
            if (result == p.first) {
                p.second++;

                cout << p.second << endl;
            } else if (result > p.first) {
                p.first = result;
                p.second = 1;
            }
            return;
        }
        solve(nums, idx + 1, result | nums[idx]);

        solve(nums, idx + 1, result);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        vector<int> v;
        solve(nums, 0, 0);

        // cout << p.first << endl;
        return p.second;
    }
};