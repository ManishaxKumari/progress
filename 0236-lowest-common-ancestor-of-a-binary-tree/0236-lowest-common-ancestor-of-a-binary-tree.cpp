/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //BASE CASE
        if(root==nullptr) return nullptr; 
        if(root==p || root==q) return root;
        //POSTORDER - for decide lca we need left and right answer both 
        TreeNode* leftside=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightside=lowestCommonAncestor(root->right,p,q);
        //PROCESS
        if(leftside!=nullptr && rightside!=nullptr) return root; // if you found both return root -> lca
        return (leftside!=nullptr) ? leftside : rightside; // if only found one then return what found
    }
};