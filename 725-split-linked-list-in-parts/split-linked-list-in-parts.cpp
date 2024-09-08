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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result(k, nullptr);
        ListNode* temp = head;
        int size = 0;

        while (temp != NULL) {
            size++;
            temp = temp->next;
        }

        int split = size / k;
        int extra = size % k;
        ListNode* current = head;
        ListNode* prev = nullptr;

        for (int i = 0; i < k && current != nullptr; i++) {

            result[i] = current;
            int currSize = split + (extra > 0 ? 1 : 0);
            extra--;

            for (int j = 0; j < currSize; j++) {
                prev = current;
                current = current->next;
            }
            if (prev != NULL) {
                prev->next = NULL;
            }
        }

        return result;
    }
};