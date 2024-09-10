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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head && !head->next) {
            return head;
        }
        ListNode* prev = head;
        // ListNode* pres = head->next;

        while (prev && prev->next) {
            int k = gcd(prev->val, prev->next->val);
            // cout << k <<endl;
            // break;
            ListNode* newNode = new ListNode(k);

            newNode->next = prev->next;
            prev->next = newNode;

            prev = newNode->next;
        }

        return head;
    }
};