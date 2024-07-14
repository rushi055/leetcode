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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }

        return dummy.next;

    //      ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    //     if (l1 == nullptr) return l2;
    // if (l2 == nullptr) return l1;

    // // Recursive case
    // if (l1->val < l2->val) {
    //     l1->next = mergeTwoLists(l1->next, l2);
    //     return l1;
    // } else {
    //     l2->next = mergeTwoLists(l1, l2->next);
    //     return l2;
    // }
    //      }
    }
};
