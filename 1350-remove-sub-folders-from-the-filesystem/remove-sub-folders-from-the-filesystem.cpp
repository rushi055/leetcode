class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;

        for (int i = 0; i < folder.size(); i++) {
            if (ans.empty() || folder[i].find(ans.back() + "/") != 0) {
                ans.push_back(folder[i]);
            }
        }

        return ans;
    }
};
