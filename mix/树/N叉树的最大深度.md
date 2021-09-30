层序遍历
```C++
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        queue<Node *> q;
        if (root != nullptr)
            q.push(root);
        int res = 0;
        while (!q.empty()){
            ++ res;
            int len = q.size();
            for (int i = 0; i < len; ++ i){
                auto t = q.front();
                q.pop();
                for (int i = 0; i < t->children.size(); ++ i){
                    q.push(t->children[i]);
                }
            }
        }
        return res;
    }
};
```
递归
```C++
class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) return 0;
        int depth = 0; // 这个对最后一层起作用 然后就是每层比较的时候作个存值的容器
        for (int i = 0; i < root->children.size(); ++ i){
            depth = max(depth, maxDepth(root->children[i]));
        }
        return depth + 1;
    }
};
```
