class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<int, int> mp;
        int m = tasks.size();

        for (auto& it : tasks) {
            mp[it]++;
        }
        priority_queue<int> pq;
        int time = 0;

        for (auto& it : mp) {
            pq.push(it.second);
        }

        while (!pq.empty()) {
            vector<int> temp;
            for (int i = 0; i < n + 1; i++) {//n intervals
                if (!pq.empty()) {
                    temp.push_back(pq.top() - 1);
                    pq.pop();
                }
            }

            for (int& freq : temp) {
                if (freq > 0)
                    pq.push(freq);
            }

            if (pq.empty()) {
                time += temp.size();
            } else {
                time += (n + 1);
            }
        }

        return time;
    }
};