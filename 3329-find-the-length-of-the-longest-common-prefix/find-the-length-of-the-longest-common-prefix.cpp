struct TrieNode {
    TrieNode* children[10]; // 0, 1, 2...9
};

class Solution {
public:
    TrieNode* getTrieNode() {
        TrieNode* node = new TrieNode();
        for (int i = 0; i < 10; i++) {
            node->children[i] = nullptr;
        }

        return node;
    }

    void insert(int num, TrieNode* root) {
        TrieNode* crawl = root;
        string numStr = to_string(num);

        for (char ch : numStr) {
            int idx = ch - '0';
            if (!crawl->children[idx]) {
                crawl->children[idx] = getTrieNode();
            }

            crawl = crawl->children[idx];
        }
    }

    // returns the length of th elongest prefix
    int search(int num, TrieNode* root) {
        TrieNode* crawl = root;
        string numStr = to_string(num);
        int length = 0;

        for (char ch : numStr) {
            int idx = ch - '0';
            if (crawl->children[idx]) {
                length++;
                crawl = crawl->children[idx];
            } else {
                break;
            }
        }

        return length;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode* root = getTrieNode(); // TRIE

        for (int num : arr1) {
            insert(num, root);
        }

        int result = 0;
        for (int num : arr2) {
            result = max(result, search(num, root));
        }

        return result;
    }
};
// class Solution {
// public:
//     int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
//         int n = arr1.size();
//         int m = arr2.size();
//         int ans = 0;

//         set<string> s1;

//         for (int i = 0; i < n; i++) {
//             string numStr = to_string(arr1[i]);
//             for (int k = 1; k <= numStr.length(); k++) {
//                 s1.insert(numStr.substr(0, k));
//             }
//         }

//         for (int i = 0; i < m; i++) {
//             string numStr = to_string(arr2[i]);
//             for (int k = 1; k <= numStr.length(); k++) {
//                 string prefix = numStr.substr(0, k);
//                 if (s1.find(prefix) != s1.end()) {
//                     ans = max(ans, (int)prefix.length());
//                 }
//             }
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
//         int n = arr1.size();
//         int m = arr2.size();
//         int ans = 0;

//         set<int> s1;

//         for (int i = 0; i < n; i++) {
//             int k = to_string(arr1[i]).length();
//             while (k > 0) {
//                 int a = arr1[i] / pow(10, k - 1);
//                 s1.insert(a);
//                 // cout<<k<<" "<<a<<endl;
//                 k--;
//             }
//         }
//         for (int i = 0; i < m; i++) {
//             int k = to_string(arr2[i]).length();
//             while (k > 0) {
//                 int a = arr2[i] / pow(10, k - 1);
//                 if (s1.find(a) != s1.end()) {
//                     ans = max(ans, a);
//                 }
//                 k--;
//             }
//         }
//         int result = to_string(ans).length();
//         // for(auto it : s1){
//         //     cout<<it<<endl;
//         // }
//         return result;
//     }
// };