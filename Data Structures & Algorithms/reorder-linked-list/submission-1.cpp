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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        auto right = slow->next;
        cout << "right=" << right->val << endl;
        slow->next = nullptr;

        ListNode* prev = nullptr;
        while (right) {
            auto next = right->next;
            right->next = prev;
            prev = right;
            right = next;
        }
        right = prev;
        cout << "right=" << right->val << endl;

        auto left = head;
        while (left && right) {
            auto leftNext = left->next;
            auto rightNext = right->next;
            left->next = right;
            right->next = leftNext;
            right = rightNext;
            left = leftNext;
        }
        cout << "right=" << (right ? right->val : -1) << endl;
        cout << "left=" << (left ? left->val : -1) << endl;
    }
};
