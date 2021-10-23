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
// 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *res = NULL;
        for (ListNode *l : lists)
            res = merge(res, l);
        return res;
    }

    ListNode *merge(ListNode *a, ListNode *b) {
        ListNode *dummy = new ListNode(-1);
        auto t = dummy;
        while (a != nullptr && b != nullptr) {
            if (a->val > b->val) {
                t->next = b;
                b = b->next;
            } else {
                t->next = a;
                a = a->next;
            }

            t = t->next;
        }
        if (a != nullptr) t ->next = a;
        if (b != nullptr) t->next = b;
        return dummy->next;
    }
};