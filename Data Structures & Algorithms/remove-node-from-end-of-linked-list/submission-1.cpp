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
        ListNode dummy(100);
        dummy.next = head;
        auto left = &dummy;
        auto right = head;

        int i = 0;
        while (right && i < n) {
            ++i;
            right = right->next;
        }
        while (right) {
            right = right->next;
            left = left->next;
        }

        left->next = left->next->next;
        return dummy.next;
    }
};
