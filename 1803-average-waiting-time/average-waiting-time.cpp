class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        double totalWT = 0;
        int endT = 0;

        for (int i = 0; i < n; ++i) {
            int arrival = customers[i][0];
            int timeToServe = customers[i][1];

            if (endT > arrival) {
                totalWT += (endT - arrival) + timeToServe;
                endT += timeToServe;
            } else {
                totalWT += timeToServe;
                endT = arrival + timeToServe;
            }
        }

        return totalWT / n;
    }
};