class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        sort(timePoints.begin(), timePoints.end());

        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {

            if (timePoints[i % n] == timePoints[(i + 1) % n]) {
                ans = 0;
                break;
            }
            int hr1 = stoi(timePoints[i].substr(0, 2));
            int mine1 = stoi(timePoints[i].substr(3, 2));
            int t1 = hr1 * 60 + mine1;

            int hr2 = stoi(timePoints[(i + 1) % n].substr(0, 2));
            int mine2 = stoi(timePoints[(i + 1) % n].substr(3, 2));
            int t2 = hr2 * 60 + mine2;

            int k = min(abs(t1 - t2), 1440 - (t1 - t2));

            ans = min(ans, k);
        }

        return ans;
    }
};