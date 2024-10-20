class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> v;
        string s = "";
        int n = target.length();

        for (int i = 0; i < n; i++) {
            s.push_back('a');
            v.push_back(s);

            while (s.back() != target[i]) {
                char ch = s.back();
                ch++;
                s.pop_back();
                s.push_back(ch);
                v.push_back(s);
            }
        }
        return v;
    }
};

//