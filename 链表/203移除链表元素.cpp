class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        auto pre = dummy;
        auto cur = head;
        while (cur != nullptr) {
            if (cur->val == val) {
                cur = cur->next;
                pre->next = cur;
            } else {
                pre = pre->next;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};

// 有bug 42 / 46
// [1,2,6,3,4,5,6] 
// 6
// 输出 [1,2,3,4,5,6]
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(-1);
        auto p = dummy;
        while (head != nullptr) {
            if (head->val == val) head = head->next;
            else {
                p->next = head;
                head = head->next;
                p = p->next;
            }
        }
        return dummy->next;
    }
};