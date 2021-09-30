给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：
```C++
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
```
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。
```C++
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node *> q;
        if (root != nullptr) q.push(root);
        while (!q.empty()){
            int len = q.size();
            vector<int> vec;
            Node *pre, *cur; // 定义注意下
            for (int i = 0; i < len; ++i){
                if (i == 0){
                    pre = q.front();
                    q.pop();
                    cur = pre;
                } else {
                    cur = q.front();
                    q.pop();
                    pre -> next = cur;
                    pre = pre ->next;
                }
                if (cur->left != nullptr) q.push(cur->left);
                if (cur->right != nullptr) q.push(cur->right);
            }
            pre->next = nullptr;
        }
        return root;
        
    }
};
```