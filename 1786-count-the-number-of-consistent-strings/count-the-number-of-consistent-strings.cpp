class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = 0;
        unordered_set<char> st;
        for (auto& it : allowed) {
            st.insert(it);
        }

        for (int i = 0; i < words.size(); i++) {
            int size = words[i].length();
            int z = 0;
            for (int j = 0; j < size; j++) {
                if (st.find(words[i][j]) != st.end()) {
                    z++;
                } else {
                    break;
                }
            }
            if(z==size){
                count++;
            }
        }
        return count;
    }
};