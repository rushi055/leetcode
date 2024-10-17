class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();
        int ans = num;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                string v = s;
                swap(v[i],v[j]);
                ans = max(ans,stoi(v));
            }
        }
        return ans;
    }
};