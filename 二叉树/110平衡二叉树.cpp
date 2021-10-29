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
/*
给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：
    
    一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。

平衡树 acwing 253普通平衡树
*/
class Solution {
public:
    bool ans;

    bool isBalanced(TreeNode* root) {
        ans = true;
        dfs(root);
        return ans;    
    }

    int dfs(TreeNode *root) {
        if (root == nullptr) return 0;
        int lh = dfs(root->left);
        int rh = dfs(root->right);
        if (abs(lh - rh) > 1) ans = false;
        return max(lh, rh) + 1;
    }
};