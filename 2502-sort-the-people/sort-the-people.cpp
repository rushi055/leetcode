class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> v;
        int n = names.size();

        for (int i = 0; i < n; i++) {
            v.emplace_back(heights[i], names[i]);
        }
        sort(v.begin(), v.end(),
             [](pair<int, string>& a, pair<int, string>& b) {
                 return a.first > b.first;
             });

        vector<std::string> ans;
        for (const auto& pair : v) {
            ans.push_back(pair.second);
        }
        return ans;
    }
};