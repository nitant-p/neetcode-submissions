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
        ListNode dummy;
        ListNode* next = &dummy;
        
        vector<int> minsInd;

        bool process = true;
        while (process) {
            process = false;
            int i = 0;
            int min = INT_MAX;

            while (i < lists.size()) {
                auto& l = lists[i];
                if (l == nullptr or l->val > min) {
                    ++i;
                    continue;
                } else {
                    process = true;
                    if (l->val == min) {
                        minsInd.push_back(i);
                    } else {
                        min = l->val;
                        minsInd.clear();
                        minsInd.push_back(i);
                    }
                }
                    ++i;
            }

            // build and advance
            for (auto l : minsInd) {
                next->next = new ListNode(min);
                next = next->next;

                lists[l] = lists[l]->next;
            }

            minsInd.clear();
        }

        return dummy.next;
        
        
    }
};
