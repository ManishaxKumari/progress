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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==nullptr) return ans;
        queue<TreeNode*> q;
        bool direction = true;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> level(n);
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                int index=direction? i : n-i-1;
                level[index]=node->val;
                if(node->left !=nullptr) q.push(node->left);
                if(node->right !=nullptr) q.push(node->right);
            }
            direction=!direction;
            ans.push_back(level);
        }
        return ans;
    }
};