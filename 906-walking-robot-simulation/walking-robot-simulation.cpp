
class Solution {
public:
    int robotSim(std::vector<int>& commands,std::vector<std::vector<int>>& obstacles) {
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int dirIndex = 0;
        set<pair<int, int>> obstacleSet;

        for (const auto& obstacle : obstacles) {
            obstacleSet.insert({obstacle[0], obstacle[1]});
        }

        int x = 0, y = 0;
        int maxDistance = 0;

        for (int command : commands) {
            if (command == -2) {
                dirIndex = (dirIndex + 3) % 4;
            } else if (command == -1) {
                dirIndex = (dirIndex + 1) % 4;
            } else {
                for (int step = 0; step < command; ++step) {
                    int newX = x + directions[dirIndex].first;
                    int newY = y + directions[dirIndex].second;

                    if (obstacleSet.count({newX, newY})) {
                        break;
                    }

                    x = newX;
                    y = newY;

                    maxDistance = max(maxDistance, x * x + y * y);
                }
            }
        }

        return maxDistance;
    }
};
