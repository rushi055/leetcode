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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        ListNode* newN = head;

        for (int i = 0; i < n; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            return head->next;
        }
        while (temp->next != NULL) {
            temp = temp->next;
            newN = newN->next;
        }
        ListNode* delN = newN->next;
        newN->next = newN->next->next;
        // free(delN);
        return head;
    }
};