class Solution {
public:
    bool canPlaceFlowers(vector<int>& V, int n) {
       int count=0;
       if (n == 0) {
            return true;
        }
        for (int i = 0; i < V.size(); i++) {
           if (V[i] == 0) {
               if ((i == 0 || V[i - 1] == 0) && (i == V.size() - 1 || V[i + 1] == 0)) {
                   V[i] = 1; 
                   count++;
               }
           }
       }
       if(count>=n){
           return true;
       }
       else{
           return false;
       }
    }
};