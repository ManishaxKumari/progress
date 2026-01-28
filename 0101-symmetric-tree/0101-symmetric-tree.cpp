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
    bool dfs(TreeNode* p,TreeNode* q){
        if(p==nullptr && q==nullptr) return true;
        if(p==nullptr || q==nullptr) return false;
        if(p->val !=q->val) return false;
        return dfs(p->left,q->right) && dfs(p->right,q->left);
    }
    bool isSymmetric(TreeNode* root) {
        TreeNode* p=root->left;
        TreeNode* q=root->right;
        return dfs(p,q);
    }
};