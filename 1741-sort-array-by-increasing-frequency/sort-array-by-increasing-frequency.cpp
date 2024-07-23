class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> mp;

        for (auto it : nums) {
            mp[it]++;
        }

        // vector<pair<int, int>> v(mp.begin(), mp.end());

        // auto mycomp = [](pair<int, int>& a, pair<int, int>& b) {
        //     if (a.second == b.second) {
        //         return a.first > b.first;
        //     }
        //     return a.second < b.second;
        // };
        // sort(v.begin(), v.end(), mycomp);

        // vector<int> result;
        // for (const auto& p : v) {
        //     result.insert(result.end(), p.second, p.first);
        // }

        // return result;
        
         std::sort(nums.begin(), nums.end(), [&map](int a, int b) {
            if (map[a] == map[b]) {
                return a > b; 
            }
            return map[a] < map[b]; 
        });

        return nums;
    }
};
