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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

        for (int i = 0; i < lists.size(); i++) {
            ListNode* temp = lists[i];
            while (temp != nullptr) {
                pq.push(temp->val);
                temp = temp->next;
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        while (!pq.empty()) {
            ListNode* node = new ListNode(pq.top());
            pq.pop();
            current->next = node;
            current = current->next;
        }

        return dummy->next;
    }
};