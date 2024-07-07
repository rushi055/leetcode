/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        map<ListNode*, int> mp;
        ListNode* temp = headA;
        ListNode* temp2 = headB;
        int count = 1;

        while (temp != NULL) {
            mp[temp] = count;
            count++;
            temp = temp->next;
        }

        while (temp2 != NULL) {
            if (mp.find(temp2) != mp.end()) {
                return temp2;
            }
            temp2 = temp2->next;
        }
        return NULL;
    }
};