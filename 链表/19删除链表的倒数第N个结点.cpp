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
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        auto p = dummy;
        auto t = head;
        while (n --) {
            t = t->next;
        }
        while (t != nullptr) {
            t = t->next;
            p = p->next;
        }
        p->next = p->next->next;
        return dummy->next;
    }
};