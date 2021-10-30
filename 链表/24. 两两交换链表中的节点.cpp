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

// 中间一个易错点是nullptr->nullptr的问题
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        if (head == nullptr) return head;
        ListNode *pre = dummy, *cur = head, *ne = head->next;
        while (cur != nullptr) {
            ne = cur->next;
            if (ne == nullptr) return dummy->next;

            pre->next = ne;
            cur->next = ne->next;
            ne->next = cur;

            pre = cur;
            cur = cur->next;
        }
        return dummy->next;
    }
};