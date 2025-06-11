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
    int magic(TreeNode* root, int &maxsum){
        if(root==nullptr){
            return 0;
        }
        int left=magic(root->left,maxsum);
        int right=magic(root->right,maxsum);
        //case 1 ->neeche hi kuch acha mil gya !! ye mil gya h isko return nhi karna h aage 
        int found=left+right+root->val;
        //case2->koi ak acha mila !! isko return kar sakte h 
        int onlyone=max(left,right)+root->val;
        //case3-> only root acha h , isko bhi return kar sakte h
        int onlynode=root->val;
        maxsum=max({maxsum,found,onlyone,onlynode});
        return max(onlynode,onlyone);

    }
    int maxPathSum(TreeNode* root) {
        int maxsum=INT_MIN;
        magic(root, maxsum);
        return maxsum;
    }
};