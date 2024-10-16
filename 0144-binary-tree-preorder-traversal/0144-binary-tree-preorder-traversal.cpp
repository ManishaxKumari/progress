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

    void ans(vector<int> &res,TreeNode* root){
        if(root==NULL) {
            return;
        }
        res.push_back(root->val);
        ans(res,root->left);
        ans(res,root->right);
        
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>res;
        ans(res,root);
        return res;
    }
};