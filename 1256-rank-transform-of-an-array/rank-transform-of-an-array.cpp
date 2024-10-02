class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<pair<int, int>> v;
        int n = arr.size();
        vector<int> ans(n);
        if(arr.size()==0){
            return {};
        }

        for (int i = 0; i < n; i++) {
            v.push_back({arr[i], i});
        }

        sort(v.begin(), v.end());

        int rank = 1;
        ans[v[0].second] = rank;

        for (int i = 1; i < n; i++) {
            if (v[i].first == v[i - 1].first) {
                ans[v[i].second] = rank;
            } else {
                rank++;
                ans[v[i].second] = rank;
            }
        }
        return ans;
    }
};
