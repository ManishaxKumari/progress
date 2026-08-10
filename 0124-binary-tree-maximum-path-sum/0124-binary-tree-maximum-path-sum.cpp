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

        int whole=left+right+root->val;
        int onlyoneside=max(left,right)+root->val;
        int onlyroot= root->val;
        maxdia=max({whole,onlyoneside,onlyroot,maxdia});
        return max(onlyroot,onlyoneside);
    }
    int maxPathSum(TreeNode* root) {
        int maxdia=INT_MIN;
        solve(root,maxdia);
        return maxdia;
    }
};