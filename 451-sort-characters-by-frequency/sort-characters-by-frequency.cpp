class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;

        for (auto it : s) {
            mp[it]++;
        }

        vector<pair<char, int>> v(mp.begin(), mp.end());
        auto mycomp = [](pair<char, int>& a, pair<char, int>& b) {
            return a.second > b.second;
        };
        sort(v.begin(), v.end(), mycomp);

        string ans;
        for (const auto& p : v) {
            ans.append(p.second, p.first); // Append 'p.first' 'p.second' times
        }
        return ans;
    }
};