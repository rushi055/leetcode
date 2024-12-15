class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        sort(
            events.begin(), events.end(),
            [](const vector<int>&a, const vector<int>&b ) { return a[1] < b[1]; });

        int k = events[0][1];
        int ans = events[0][0];
        for (int i = 0; i < events.size(); i++){
            cout<<events[i][1]<<" "<<endl;
        }
        for (int i = 1; i < events.size(); i++) {
            if (k < (events[i][1] - events[i - 1][1])) {
                k = events[i][1] - events[i - 1][1];
                ans = events[i][0];
            }
            else if(k == (events[i][1] - events[i - 1][1])){
                ans = min(events[i][0],ans);
            }
            
        }
        return ans;
    }
};