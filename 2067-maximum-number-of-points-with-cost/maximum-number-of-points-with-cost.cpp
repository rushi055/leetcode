// TLE 
// class Solution {
// public:
//     long long ans = LLONG_MIN;

//     long long solve(vector<vector<int>>& points, int i, int idx, long long result) {
//         int n = points.size();
//         int m = points[0].size();
//         if (i >= n) {
//             return result;
//         }
//         long long maxResult = LLONG_MIN; 
//         for (int a = 0; a < m; a++) {
//             result += points[i][a];
//             result -= abs(idx - a);

//             maxResult = max(maxResult, solve(points, i + 1, a, result));

//             result -= points[i][a];
//             result += abs(idx - a);
//         }
//         return maxResult; 
//     }

//     long long maxPoints(vector<vector<int>>& points) {
//         int n = points.size();
//         int m = points[0].size();
//         long long k;
//         for (int i = 0; i < m; i++) { 
//             k = solve(points, 1, i, points[0][i]); 
//             ans = max(ans, k);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    typedef long long ll;
    ll maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        vector<ll> prev(n);
        int score = 0;
        
        for(int col = 0; col < n; col++) {
            prev[col] = points[0][col];
        }
        
        for(int i = 1; i < m; i++) {
            vector<ll> curr(n);
            auto left = curr, right = curr;
            
            left[0] = prev[0];
            for(int j = 1; j < n; j++) {
                left[j] = max(prev[j], left[j-1] - 1);
            }
            
            right[n-1] = prev[n-1];
            for(int j = n-2; j >= 0; j--) {
                right[j] = max(prev[j], right[j+1] - 1);
            }
            
            for(int j = 0; j < n; j++) {
                curr[j] = points[i][j] + max(left[j], right[j]);
            }
            
            prev = curr;
        }
        return *max_element(prev.begin(), prev.end());
    }
};

