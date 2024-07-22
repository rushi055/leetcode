class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;

        for (auto it : nums) {
            mp[it]++;
        }

        vector<pair<int, int>> v(mp.begin(), mp.end());
        auto mycomp = [](pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        };
        sort(v.begin(), v.end(), mycomp);

        
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(v[i].first);
        }

        return result;
    }
};