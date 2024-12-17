class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> count(26, 0);
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
        }
        string result;

        int i = 25;
        while (i >= 0) {
            if (count[i] == 0) {
                i--;
                continue;
            }

            char ch = 'a' + i;
            int cnt = min(count[i], repeatLimit);

            result.append(cnt, ch);
            count[i]-=cnt;
            if(count[i]!=0){
                int j=i-1;
                while(j>=0){
                    if(count[j]!=0){
                        int sch = 'a' + j ;
                        result.push_back(sch);
                        count[j]--;
                        break;
                    }
                    else{
                        j--;
                    }
                }

                if(result.back()==ch){
                    break;
                }

            }
            else{
                i--;
            }

            
        }

        return result;
    }
};