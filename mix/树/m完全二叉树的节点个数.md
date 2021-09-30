层序遍历
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
    int countNodes(TreeNode* root) {
        int res = 0;
        if (root == nullptr) return res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()){
            int len = q.size();
            for (int i = 0; i < len; i ++){
                auto t = q.front();
                q.pop();
                res ++;
                if (t->left != nullptr)
                    q.push(t->left);
                if (t->right != nullptr)
                    q.push(t->right);
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
    int countNodes(TreeNode* root) {
        return getNum(root);
    }

    int getNum(TreeNode *root){ // 获取以root为根节点的树的节点数
        if (root == nullptr)
            return 0;
        int l = getNum(root->left);
        int r = getNum(root->right);
        int sum = l + r + 1;
        return sum;
    }
};
```
简化
```C++
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
```