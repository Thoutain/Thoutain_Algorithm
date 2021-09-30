和二叉树还是一样的
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
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node *> q;
        if (root != nullptr) q.push(root);
        vector<vector<int>> res;

        while (!q.empty()){
            int len = q.size();
            vector<int> tmp;
            while (len --){
                auto t = q.front();
                q.pop();
                tmp.push_back(t->val);
                for (int i = 0; i < t->children.size(); ++ i){
                    q.push(t->children[i]);
                }
            }
            res.push_back(tmp);
        }

        return res;
    }
};
```