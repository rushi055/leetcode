class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int>ans;
          for (int i = 0; i < queries.size(); i++) {
            int b = queries[i][0];
            int j = queries[i][1];
            int a =0;
            for (int k = b; k <= j; k++) {
                a = a ^ arr[k];
            }
            ans.push_back(a);
        }
        return ans;
    }
};