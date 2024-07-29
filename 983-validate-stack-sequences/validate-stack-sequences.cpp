class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        int m = popped.size();

        if (n != m) {
            return false;
        }

        stack<int> s;
        int j = 0;
        for (int i = 0; i < pushed.size(); i++) {
            s.push(pushed[i]);
            while (s.size() > 0 && s.top() == popped[j]) {
                s.pop();
                j++;
            }
        }
        return s.empty();
    }
};