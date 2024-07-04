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

////Approach-1 (Time : O(n), Space : O(1))
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* odd = head;
        ListNode* even = head->next;

        ListNode* evenStart = head->next;

        while (even != NULL && even->next != NULL) {
            odd->next = even->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }

        odd->next = evenStart;

        return head;
    }
};

// Approach-1 (Time : O(2n), Space : O(n))
// we can also do by using two while loop in first while loop we will make two pointer even and odd first we will traverse in odd nodes Time complexity O(n/2) , then we will traverse in even nodes Time complexity O(n/2)
// add save data in array or vector and then in second while loop we put the values from array in the existing linklist Time complexity O(n);
