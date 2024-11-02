class Solution {
public:
    bool isCircularSentence(string sentence) {
        char ch = sentence[0];

        for(int i=0;i<sentence.length();i++){
            if(i!=0 && sentence[i]==' '){
                if(sentence[i-1]==sentence[i+1]){
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        if(ch!=sentence[sentence.length()-1]){
            return false;
        }
        return true;
    }
};