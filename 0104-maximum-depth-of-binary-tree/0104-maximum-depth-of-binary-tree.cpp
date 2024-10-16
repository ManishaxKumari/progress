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
    int ans(int n,TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int maxr=ans(n,root->left);
        int maxl=ans(n,root->right);
        return max(maxr,maxl)+1;
    }
    int maxDepth(TreeNode* root) {
        int n;
        int a=ans(n,root);
        return a;
        
    }
};