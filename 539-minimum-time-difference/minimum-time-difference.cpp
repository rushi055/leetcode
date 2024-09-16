class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {

        int n = timePoints.size();
        vector<bool> count(1440, false);

        for (int i = 0; i < n; i++) {
            int hr1 = stoi(timePoints[i].substr(0, 2));
            int min1 = stoi(timePoints[i].substr(3, 2));
            int t1 = hr1 * 60 + min1;
            if (count[t1]) return 0;
            count[t1] = true;
        }

        int pre = -1;
        int first = -1;
        int last = -1;
        int ans = INT_MAX;

        for (int i = 0; i < 1440; i++) {
            if (count[i]) {
                if (pre == -1) {
                    pre = i;
                    first = i;
                } else {
                    ans = min(ans, i - pre);
                    pre = i;
                }
                last = i;
            }
        }
        ans = min(ans, (1440 - last + first));

        return ans;
    }
};


        // nlog(n)
        // int n = timePoints.size();
        // sort(timePoints.begin(), timePoints.end());

        // int ans = INT_MAX;
        // for (int i = 0; i < n; i++) {

        //     if (timePoints[i % n] == timePoints[(i + 1) % n]) {
        //         ans = 0;
        //         break;
        //     }
        //     int hr1 = stoi(timePoints[i].substr(0, 2));
        //     int mine1 = stoi(timePoints[i].substr(3, 2));
        //     int t1 = hr1 * 60 + mine1;

        //     int hr2 = stoi(timePoints[(i + 1) % n].substr(0, 2));
        //     int mine2 = stoi(timePoints[(i + 1) % n].substr(3, 2));
        //     int t2 = hr2 * 60 + mine2;

        //     int k = min(abs(t1 - t2), 1440 - (t1 - t2));

        //     ans = min(ans, k);
        // }

        // return ans;
//     }
// };