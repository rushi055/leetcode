class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> nextGE(nums2.size(), -1);

        for (int i = nums2.size() - 1; i >= 0; --i) {
            int element = nums2[i];

            // Remove all elements smaller than the current element
            while (!st.empty() && st.top() <= element) {
                st.pop();
            }

            // If the stack is not empty, the top element is the next greater element
            if (!st.empty()) {
                nextGE[i] = st.top();
            }

            st.push(element);
        }

        vector<int> result;
        for (int num : nums1) {
            auto it = find(nums2.begin(), nums2.end(), num);
            if (it != nums2.end()) {
                int index = distance(nums2.begin(),it);    //it - nums2.begin();
                result.push_back(nextGE[index]);
            }
        }

        return result;
    }
};

---------------------------------------------------------------------------------------------------------------------------------------------|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int, int>m;
        stack<int>st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            if(st.empty()) m[nums2[i]] = -1;
            else m[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        vector<int>ans;
        for(auto it: nums1){
            ans.push_back(m[it]);
        }
        return ans;
    }
};
