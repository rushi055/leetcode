/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));

        int dir = 0;
        int top = 0;
        int bottom = m - 1;
        int right = n - 1;
        int left = 0;

        ListNode* temp = head;

        while (top <= bottom && right >= left && temp != nullptr) {
            if (dir == 0) {
                for (int i = left; i <= right && temp != nullptr; i++) {
                    ans[top][i] = temp->val;
                    temp = temp->next;
                    // cout<<ans[top][i]<<endl;
                }
                // cout<<left <<" "<<right<<endl;
                top++;
            } else if (dir == 1) {
                for (int i = top; i <= bottom && temp != nullptr; i++) {
                    ans[i][right] = temp->val;
                    temp = temp->next;
                }
                right--;
            } else if (dir == 2) {
                for (int i = right; i >= left && temp != nullptr; i--) {
                    ans[bottom][i] = temp->val;
                    temp = temp->next;
                }
                bottom--;
            } else if (dir == 3) {
                for (int i = bottom; i >= top && temp != nullptr; i--) {
                    ans[i][left] = temp->val;
                    temp = temp->next;
                }
                left++;
            }
            dir++;

            if (dir == 4) {
                dir = 0;
            }
        }
        return ans;
    }
};