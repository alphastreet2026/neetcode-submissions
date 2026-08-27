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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode res;
        ListNode* dummy = &res;
        // 5 3
        int r = 0;
        while (l1 || l2) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            int sum = r + val1 + val2;
            if (sum < 10){
                dummy->next = new ListNode(sum);
                r = 0;
            }else{
                dummy->next = new ListNode(sum%10);
                r = 1;
            }
            dummy = dummy->next;
            cout << "d=" << dummy->val << endl;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        if (r){
            dummy->next = new ListNode(r);
        }

        return res.next;

    }
};
