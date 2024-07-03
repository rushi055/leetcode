class Solution {
public:
    int romanToInt(string s) {
        std::unordered_map<char, int> romanValues = {
            {'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}};

        int result = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (i + 1 < s.length() &&
                romanValues[s[i]] < romanValues[s[i + 1]]) {
                result -= romanValues[s[i]];
            } else {
                result += romanValues[s[i]];
            }
        }

        return result;
    }
};