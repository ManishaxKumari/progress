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
    int solve(TreeNode* root,int &maxdia){
        if(root==nullptr) return 0;
        int left=solve(root->left,maxdia);
        int right=solve(root->right,maxdia);
        if(left<0) left=0;
        if(right<0) right=0;
        maxdia=max(maxdia,left+right+root->val);
        return max(left,right)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxdia=INT_MIN;
        solve(root,maxdia);
        return maxdia;
    }
};