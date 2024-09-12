class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total_gas = 0, total_cost = 0;

        for (int i = 0; i < n; i++) {
            total_gas += gas[i];
            total_cost += cost[i];
        }

        if (total_cost > total_gas) {
            return -1;
        }

        int idx = 0;
        int current_gas = 0;
        for (int i = 0; i < gas.size(); i++) {
            current_gas += gas[i] - cost[i];
            if (current_gas < 0) {
                idx = i + 1;
                current_gas = 0;
            }
        }

        return idx;
    }
};
