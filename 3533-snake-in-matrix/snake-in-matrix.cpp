class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        pair<int, int> mp = {0, 0};

        for (int i = 0; i < commands.size(); i++) {
            if (commands[i][0] == 'D') {
                mp.first += 1;
            } else if (commands[i][0] == 'U') {
                mp.first -= 1;
            } else if (commands[i][0] == 'R') {
                mp.second += 1;
            } else {
                mp.second -= 1;
            }
        }
        int k = (mp.first * n) + mp.second;
        return k;
    }
};