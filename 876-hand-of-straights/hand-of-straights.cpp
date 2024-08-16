// class Solution {
// public:
//     bool isNStraightHand(vector<int>& hand, int groupSize) {

//         if (hand.size() % groupSize != 0) {
//             return false;
//         }
//         map<int, int> mp;

//         for (auto& it : hand) {
//             mp[it]++;
//         }
//         for (auto it : mp) {
//             int card = it.first;
//             int count = it.second;
//             if (count > 0) {
//                 for (int i = 0; i < groupSize; ++i) {
//                     if (mp[card + i] < count) {
//                         return false; 
//                     }
//                     mp[card + i] -= count; 
//                 }
//             }
//         }
        
//         return true;
//     }
// };

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n % groupSize) {
            return false;
        }

        map<int, int> mp;
        for(int &handNumber : hand) {
            mp[handNumber]++; //O(nlogn)
        }

        while(!mp.empty()) { //O(n*groupSize)

            int curr = mp.begin()->first; 

            for(int i = 0; i < groupSize; i++) {
                if(mp[curr + i] == 0) {
                    return false;
                }

                mp[curr+i]--;
                if(mp[curr+i] < 1) {
                    mp.erase(curr+i);
                }
            }

        }

        return true;
        
    }
};