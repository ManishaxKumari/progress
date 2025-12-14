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
        if(node->left == nullptr) return node->right;
        if(node->right == nullptr) return node->left;
        TreeNode* leftsubtree=node->left;
        TreeNode* leftmost_rightsubtree=node->right;
        while(leftmost_rightsubtree->left!=NULL){ //danger zone
            leftmost_rightsubtree =leftmost_rightsubtree->left;
        }
        leftmost_rightsubtree->left=leftsubtree;
        return node->right;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;
        if(root->val == key){
            return connector(root);
        }
          TreeNode* node=root;
        while(node!=nullptr){
            if(node->val > key){
                if(node->left && node->left->val == key){
                    node->left=connector(node->left);
                    break;
                }
                else{
                    node=node->left;
                }
            }
            else if(node->val < key){
                 if( node->right && node->right->val == key){
                    node->right=connector(node->right);
                    break;
                }
                else{
                    node=node->right;
                }
            }
        }
        return root;
    }
};