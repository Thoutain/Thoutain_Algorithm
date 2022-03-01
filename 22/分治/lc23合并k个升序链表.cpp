#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *merge(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode(-1);
    auto t = dummy;

    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val < l2->val) {
            t->next = l1;
            l1 = l1->next;
        } else {
            t->next = l2;
            l2 = l2->next;
        }

        t = t->next;
    }

    if (l1 != nullptr) t->next = l1;
    if (l2 != nullptr) t->next = l2;

    return dummy->next;
}

ListNode *mergeKLists(vector<ListNode *> lists) {
    ListNode *res = nullptr;
    for (ListNode *l : lists)
        res = merge(res, l);
    return res;
}

// 输入未解决
int main() {

}