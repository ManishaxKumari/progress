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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        //brute force
        int n=preorder.size();
        TreeNode* root= new TreeNode(preorder[0]);
        int i=1;
        TreeNode* temp=root;
        while(i<n){
            if(temp->val > preorder[i]){
                if(temp->left == nullptr){
                    temp->left=new TreeNode(preorder[i]);
                    i++;
                    temp=root;
                }
                else{
                    temp=temp->left;
                }
            }
            else{
                if(temp->right == nullptr){
                    temp->right=new TreeNode(preorder[i]);
                    i++;
                    temp=root;
                }
                else{
                    temp=temp->right;
                }
            }
        }
        return root;
    }
};