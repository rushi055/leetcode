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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> st;
        for (auto& it : nums) {
            st.insert(it);
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* pres = head;

        while (pres) {
            if (st.find(pres->val) != st.end()) {
                prev->next = pres->next;
                pres = prev->next;
            } else {
                prev = pres;
                pres = pres->next;
            }
        }
        head = dummy->next;
        return head;
    }
};