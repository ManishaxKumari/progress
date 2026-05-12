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
    typedef long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,ll>>q;
        q.push({root,0});
        ll maxw=0;
        while(!q.empty()){
            ll n =q.size();
            ll minidx=q.front().second; //normalization base
            ll first,last;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front().first;
                ll idx=q.front().second-minidx;
                q.pop();
                if(i==0) first=idx;
                if(i==n-1) last=idx;
                if(node->left !=nullptr) {
                    q.push({node->left,2*idx+1});
                }
                if(node->right!=nullptr){
                    q.push({node->right,2*idx+2});
                }
            }
            maxw=max(maxw,last-first+1);
        }
        return maxw;
    }
};