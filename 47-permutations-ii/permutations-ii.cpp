class Solution {
public:
    vector<vector<int>> result;
    int n;

    void solve(unordered_map<int, int> mp, vector<int>& temp) {

        if (temp.size() == n) {
            result.push_back(temp);
            return;
        }
        // for (auto it : mp) {
        //     if (it.second == 0) {
        //         continue;
        //     }

        //     temp.push_back(it.first);
        //     mp[it.first]--;

        //     solve(mp, temp);

        //     temp.pop_back();
        //     mp[it.first]++;
        // }
        for (auto& [num, count] : mp) {

            if (count == 0) {
                continue;
            }

            temp.push_back(num); // included the number
            mp[num]--;

            solve(mp, temp); // other options

            temp.pop_back(); // removed the number
            mp[num]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        unordered_map<int, int> mp;
        vector<int> temp;

        for (auto it : nums) {
            mp[it]++;
        }

        solve(mp, temp);

        return result;
    }
};