class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        string ans = "";
        int a = k;
        while (word.length() < k) {
            for (int i = 0; i < word.length(); i++) {
                char ch = (word[i] - 'a' + 1) % 26 + 'a';
                ans.push_back(ch);
            }
            word += ans;
            ans ="";
        }
        return word[k-1];
    }
};