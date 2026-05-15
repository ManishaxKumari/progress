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
    TreeNode* connector(TreeNode* node){
        if(node->left ==nullptr) return node->right;
        if(node->right==nullptr) return node->left;
        //store left subtree -> go to leftmost node of right subtree and connect it to left subtree then return right subtree 
        TreeNode* left_subtree=node->left;
        TreeNode* right_subtree=node->right;
        while(right_subtree->left !=nullptr){ // find leftmost node of rightsubtree
            right_subtree=right_subtree->left;
        }

        right_subtree->left=left_subtree;
        return node->right; //connect with this now !


    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return nullptr;
        if(root->val == key) return connector(root);

        TreeNode* node=root;
        while(node!=nullptr){ // find the node you want to delete it
            if(node->val > key){
                if(node->left && node->left->val ==key){
                    node->left = connector(node->left);
                    break;
                }
                else{
                    node=node->left;
                }
            }
            else{
                if(node->right && node->right->val==key){
                    node->right=connector(node->right);
                }
                else{
                    node=node->right;
                }
            }
        }
        return root;
    }
};