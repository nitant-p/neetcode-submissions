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
        vector<int> digits;
        int carry = 0;

        ListNode dummy;
        ListNode* curr = &dummy;

        while (l1 != nullptr or l2 != nullptr) {
            int sum = 0;
            if (l1 != nullptr and l2 != nullptr) {
                sum = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            } else if (l1 != nullptr) {
                sum = l1->val + carry;
                l1 = l1->next;
            } else if (l2 != nullptr) {
                sum = l2->val + carry;
                l2 = l2->next;
            } else {
                sum = carry;
            }

            if (sum >= 10) {
                sum -=10;
                carry = 1;
            } else carry = 0;

            curr->next = new ListNode(sum);
            curr = curr->next;
        }

        if (carry > 0) curr->next = new ListNode(carry);


        return dummy.next;

    }
};
