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

const auto init = []() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    return nullptr;
}();

// Approach-1 (Using Simple looping)
// T.C : O(n)
// S.C : O(1)
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minDistance = INT_MAX;

        ListNode* prev = head;
        ListNode* curr = head->next;
        int currPosition = 1;
        int previousCriticalIndex = 0;
        int firstCriticalIndex = 0;

        while (curr->next != NULL) {

            if ((curr->val < prev->val && curr->val < curr->next->val) ||
                (curr->val > prev->val && curr->val > curr->next->val)) {

                if (previousCriticalIndex == 0) {
                    previousCriticalIndex = currPosition;
                    firstCriticalIndex = currPosition;
                } else {
                    minDistance =
                        min(minDistance, currPosition - previousCriticalIndex);
                    previousCriticalIndex = currPosition;
                }
            }

            currPosition++;
            prev = curr;
            curr = curr->next;
        }

        if (minDistance == INT_MAX) {
            return {-1, -1};
        }

        int maxDistance = previousCriticalIndex - firstCriticalIndex;
        return {minDistance, maxDistance};
    }
};
