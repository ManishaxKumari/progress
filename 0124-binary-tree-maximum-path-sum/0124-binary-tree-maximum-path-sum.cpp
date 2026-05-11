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
    int solve(TreeNode* root, int &maxsum){
        if(root==nullptr) return 0;
        int left=solve(root->left,maxsum);
        int right=solve(root->right,maxsum);
        maxsum=max({maxsum,
            left+right+root->val,
            left+root->val,
            right+root->val,
            root->val
        });

        return max({
            left+root->val,
            right+root->val,
            root->val
        });
    }
    int maxPathSum(TreeNode* root) {
        int maxsum=INT_MIN;
        solve(root,maxsum);
        return maxsum;
    }
};