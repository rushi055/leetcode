class Solution {
public:
    typedef long long ll;

    ll solve(int i, int j, vector<int>& robot, vector<int>& position,
             vector<vector<ll>> &t) {
        if (i >= robot.size()) {
            return 0;
        }
        if (j >= position.size()) {
            return 1e12;
        }

        if (t[i][j] != -1) {
            return t[i][j];
        }

        ll take = abs(robot[i] - position[j]) +
                  solve(i + 1, j + 1, robot, position, t);

        ll skip = solve(i, j + 1, robot, position, t);

        return t[i][j] = min(take, skip);
    }

    long long minimumTotalDistance(vector<int>& robot,
                                   vector<vector<int>>& factory) {
        int n = robot.size();

        vector<int> position;
        for (const auto& fac : factory) {
            int pos = fac[0];
            int limit = fac[1];

            for (int j = 0; j < limit; j++) {
                position.push_back(pos);
            }
        }
        sort(robot.begin(), robot.end());
        sort(position.begin(), position.end());

        vector<vector<ll>> t(n + 1, vector<ll>(position.size() + 1, -1));

        return solve(0, 0, robot, position, t);
    }
};
