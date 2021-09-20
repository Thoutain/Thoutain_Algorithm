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
// wrong 187 / 208
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr && n == 1)
            return nullptr;
        auto t = head;
        while (n--) {
            t = t->next;
        }
        auto p = head;
        auto cur = head;
        while (t != nullptr) {
            t = t->next;
            p = cur;
            cur = cur->next;
        }
        p->next = cur->next;

        return head;
    }
};

// right version
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
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        auto p = dummy;
        auto cur = head;
        auto t = head;
        while (n --) {
            t = t->next;
        }
        while (t != nullptr) {
            t = t->next;
            p = p->next;
            cur = cur->next;
        }
        p->next = cur->next;
        return dummy->next;
    }
};