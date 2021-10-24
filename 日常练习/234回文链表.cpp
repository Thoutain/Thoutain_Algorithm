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
    bool isPalindrome(ListNode* head) {
        vector<int> res;
        while (head != nullptr) {
            res.push_back(head->val);
            head = head->next;
        }
        int l = 0;
        int r = res.size() - 1;
        while (l < r) {
            if (res[l] != res[r]) return false;
            l ++;
            r --;
        }
        return true;
    }
};

// “正确”一点的做法
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int n = 0;
        for (ListNode *p = head; p != nullptr; p = p->next) n ++;
        if (n <= 1) return true;
        ListNode *a = head;
        for (int i = 0; i < (n + 1) / 2 - 1; i ++) a = a->next;
        ListNode *b = a->next;
        while (b) {
            ListNode *c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
        b = head;
        ListNode *tail = a;
        bool res = true;
        for (int i = 0; i < n / 2; i ++) {
            if (a->val != b->val) {
                res = false;
                break;
            }
            a = a->next;
            b = b->next;
        }
        a = tail, b = a->next;
        for (int i = 0; i < n / 2; i ++) {
            ListNode *c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
        tail->next = 0;
        return res;
    }
};