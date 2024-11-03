class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()){
            return false;
        }
        string k = s + s;
         for(int i=0;i<s.size();i++){
             if(k.substr(i,s.size())== goal){
                 return true;
             }
         }
         return false;
    }
};