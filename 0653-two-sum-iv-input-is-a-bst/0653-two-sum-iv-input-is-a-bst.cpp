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
    void inorder(TreeNode* node,vector<int> &arr){
        if(node==nullptr) return;
        inorder(node->left,arr);
        arr.push_back(node->val);
        inorder(node->right,arr);

    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        inorder(root,arr);
        int n=arr.size();
        int l=0;
        int r=n-1;
        int sum=0;
        while(l<r){
            sum=arr[l]+arr[r];
            if(sum==k){
                return true;
            }
            else if(sum>k){
                r--;
            }
            else {
                l++;
            }
        }
        return false;


    }
};