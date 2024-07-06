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

// Approach : Merge Sort
// Time : O(nlogn)
// Space : O(log n)        // recursion stack

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummyHead(0);
        ListNode* dummyTail = &dummyHead;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                dummyTail->next = list1;
                list1 = list1->next;
            } else {
                dummyTail->next = list2;
                list2 = list2->next;
            }
            dummyTail = dummyTail->next;
        }

        if (list1)
            dummyTail->next = list1;
        if (list2)
            dummyTail->next = list2;

        return dummyHead.next;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        // find mid using slow and fast pointer approach
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* head2 = slow->next;
        slow->next = NULL;
        ListNode* l = sortList(head);
        ListNode* r = sortList(head2);

        // merge two sorted halves
        return mergeTwoLists(l, r);
    }
};