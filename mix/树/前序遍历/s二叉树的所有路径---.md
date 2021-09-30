```
给定一个二叉树，返回所有从根节点到叶子节点的路径。

说明: 叶子节点是指没有子节点的节点。

示例:

输入:

   1
 /   \
2     3
 \
  5

输出: ["1->2->5", "1->3"]
```

前序遍历、回溯
```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void traversal(TreeNode *root, vector<int> &path, vector<string> &res){
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr){
            string spath;
            for (int i = 0; i < path.size() - 1; i++){
                spath += to_string(path[i]);
                spath += "->";
            }
            spath += to_string(path[path.size() - 1]);
            res.push_back(spath);
            return;
        }
        if (root->left != nullptr){
            traversal(root->left, path, res);
            path.pop_back();
        }
        if (root->right != nullptr){
            traversal(root->right, path, res);
            path.pop_back();
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> path;
        if (root == nullptr) return res;
        traversal(root, path, res);
        return res;
    }
};
```

迭代：栈
```C++
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        stack<TreeNode *> treest;
        stack<string> pathst;
        vector<string> res;
        if (root == nullptr) return res;
        treest.push(root);
        pathst.push(to_string(root->val));
        while (!treest.empty()){
            auto t = treest.top();
            treest.pop();
            string path = pathst.top();
            pathst.pop();
            if (t->left == nullptr && t->right == nullptr){
                res.push_back(path);
            }
            if (t->right != nullptr){
                treest.push(t->right);
                pathst.push(path + "->" + to_string(t->right->val));
            }
            if (t->left != nullptr){
                treest.push(t->left);
                pathst.push(path + "->" + to_string(t->left->val));
            }
        }
        return res;
    }
};
```


