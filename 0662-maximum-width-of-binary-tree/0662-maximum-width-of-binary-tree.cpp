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
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,ll>>q;
        q.push({root,0});
        ll maxw=0;
        while(!q.empty()){
            ll size=q.size();
            ll l=q.front().second;
            ll r=q.back().second;
            maxw=max(maxw,r-l+1);
            while(size--){
                TreeNode* node=q.front().first;
                ll idx=q.front().second;
                q.pop();
                if(node->left !=nullptr){
                    q.push({node->left,2*idx+1});
                }
                if(node->right!=nullptr){
                    q.push({node->right,2*idx+2});
                }
            }
        }
        return maxw;
        
    }
};