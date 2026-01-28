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
    int dfs(TreeNode* root,int &maxsum){
        if(root==nullptr) return 0;
        int left=dfs(root->left,maxsum);
        int right=dfs(root->right,maxsum);
        int pura=left+right+root->val;
        int onlyone=max(left,right)+root->val;
        int onlynode=root->val;
        maxsum=max({maxsum,pura,onlyone,onlynode});
        return max(onlyone,onlynode);

    }
    int maxPathSum(TreeNode* root) {
        int maxsum=INT_MIN;
        dfs(root,maxsum);
        return maxsum;
    }
};