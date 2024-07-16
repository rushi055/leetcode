class Solution {
public:
    set<vector<int>> st;

    void solve(vector<int>& nums, int i, vector<int>& temp) {
        if (i >= nums.size()) {
            sort(temp.begin(), temp.end());
            st.insert(temp);
            return;
        }

        temp.push_back(nums[i]);
        solve(nums, i + 1, temp);
        temp.pop_back();
        solve(nums, i + 1, temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(), nums.end());
        solve(nums, 0, temp);
        vector<vector<int>> result(st.begin(), st.end());
        return result;
    }
};



---------------------------------------------------------------------------------------------------------------------------------------------------------------

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        
        // Sort nums to handle duplicates
        sort(nums.begin(), nums.end());
        
        // Use backtracking to generate subsets
        backtrack(nums, 0, temp, result);
        
        return result;
    }
    
private:
    void backtrack(vector<int>& nums, int start, vector<int>& temp, vector<vector<int>>& result) {
        // Add the current subset to result
        result.push_back(temp);
        
        // Iterate through possible elements to add to subset
        for (int i = start; i < nums.size(); ++i) {
            // Skip duplicates
            if (i > start && nums[i] == nums[i - 1])
                continue;
            
            // Add current element to subset
            temp.push_back(nums[i]);
            
            // Recursively generate subsets
            backtrack(nums, i + 1, temp, result);
            
            // Backtrack: remove current element from subset
            temp.pop_back();
        }
    }
};


// DRY RUn
// an example array `nums = [1, 2, 2]`.

// ### Initial Setup:
// - **Input:** `nums = [1, 2, 2]`
// - **Sorting:** `nums` is sorted to `[1, 2, 2]`.

// ### Backtracking Function (`backtrack`):

// 1. **Initial Call**: 
//    - `temp = []` (empty subset initially)
//    - `result = []` (empty result initially)
//    - `start = 0`

// 2. **Iteration for `start = 0`:**

//    - **i = 0:** (`nums[0] = 1`)
//      - Add `[1]` to `temp`.
//      - **Recursive Call (`backtrack(nums, 1, [1], result)`):**
//        - Add `[1]` to `result`.

//      - **i = 1:** (`nums[1] = 2`)
//        - Add `[1, 2]` to `temp`.
//        - **Recursive Call (`backtrack(nums, 2, [1, 2], result)`):**
//          - Add `[1, 2]` to `result`.

//        - **i = 2:** (`nums[2] = 2`)
//          - Skip duplicate `[1, 2, 2]` (since `nums[i] == nums[i - 1]` and `i > start`).

//        - Backtrack: Remove `2` from `temp`, backtrack to previous state `[1]`.

//    - **i = 2:** (`nums[2] = 2`)
//      - Skip duplicate `[1, 2, 2]` (since `nums[i] == nums[i - 1]` and `i > start`).

//      - Backtrack to previous state `[]`.

// 3. **Iteration for `start = 1`:**

//    - **i = 1:** (`nums[1] = 2`)
//      - Skip duplicate `[2]` (since `nums[i] == nums[i - 1]` and `i > start`).

//      - Backtrack to previous state `[]`.

//    - **i = 2:** (`nums[2] = 2`)
//      - Skip duplicate `[2, 2]` (since `nums[i] == nums[i - 1]` and `i > start`).

//      - Backtrack to previous state `[]`.

// ### Final Result:
// - `result = [[], [1], [1, 2], [2]]`

