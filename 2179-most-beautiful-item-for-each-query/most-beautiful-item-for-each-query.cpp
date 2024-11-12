// class Solution {
// public:
//     int binarysearch(vector<vector<int>>& items, int x) {
//         int low = 0;
//         int high = items.size() - 1;
//         int ans = -1;

//         while (low <= high) {
//             int mid = low + (high - low) / 2;

//             if(items[mid][0] <=x){
//                 ans =items[mid][1];
//                 low =mid +1;
//             }
//             else{
//                 high = mid-1;
//             }
//         }
//         return ans;
//     }
//     vector<int> maximumBeauty(vector<vector<int>>& items,
//                               vector<int>& queries) {
//         sort(items.begin(), items.end());
//         vector<int> ans(queries.size());

//         vector<int>beauty

//         for (int i = 0; i < queries.size(); i++) {
//             int k =binarysearch(items,queries[i]);
//             if(k==-1){
//                 ans[i] =0;

//             }
//             else{
//                 ans[i] =k;
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:

    int customBinarySearch(vector<vector<int>>& items, int queryPrice) {
        int l = 0;
        int r = items.size()-1;

        int mid;
        int maxBeauty = 0;

        while(l <= r) {
            mid = l + (r-l)/2;

            if(items[mid][0] > queryPrice) {
                r = mid-1; //ignore current and right side items. Move to left now.
            } else {
                maxBeauty = max(maxBeauty, items[mid][1]);
                l = mid+1;
            }
        }

        return maxBeauty;
    }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        int m = queries.size();

        vector<int> result(m);
        sort(begin(items), end(items)); 

        int maxBeautySeen = items[0][1];
        for(int i = 1; i < n; i++) {
            maxBeautySeen = max(maxBeautySeen, items[i][1]);
            items[i][1] = maxBeautySeen;
        }


        for(int i = 0; i < m; i++) {
            int queryPrice = queries[i];
            result[i] = customBinarySearch(items, queryPrice);
        }

        return result;

    }
};