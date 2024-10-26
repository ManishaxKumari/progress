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
   
    int height(TreeNode* node,int &maxdia){
        if(node==nullptr) return 0;
        int left=height(node->left,maxdia);
        int right=height(node->right,maxdia);
        maxdia=max(maxdia,left+right);
        return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
       int maxdia=0;
       height(root,maxdia);
       return maxdia;

    }
};