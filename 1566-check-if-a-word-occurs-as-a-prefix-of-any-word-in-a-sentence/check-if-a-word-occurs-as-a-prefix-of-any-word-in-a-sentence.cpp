class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {

        vector<string> s;
        int l = searchWord.length();
        string k = " ";
        sentence += k;
        k="";
        for (int i = 0; i < sentence.length(); i++) {
            if (sentence[i] == ' ') {
                s.push_back(k);
                k = "";
            } else {
                k += sentence[i];
            }
        }

        // for(int i=0;i<s.size();i++){
        //     cout<<s[i]<<endl;
        // }

        for (int i = 0; i < s.size(); i++) {
            bool h = 1;
            for (int j = 0; j < l; j++) {
                if (s[i][j] != searchWord[j] ) {
                    h=0;
                    break;
                }
            }
            if(h==1){
                return i+1;
            }
        }

        return -1;
    }
};