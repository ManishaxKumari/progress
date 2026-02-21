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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        if(root->left ==nullptr && root->right ==nullptr) return 1;
        int level=1;
        int maxlevel=1;
        int maxsum=INT_MIN;
        while(!q.empty()){
            int currsum=0;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                currsum=currsum+node->val;
                if(node->left!=nullptr) q.push(node->left);
                if(node->right !=nullptr) q.push(node->right);
            }
            if(currsum>maxsum){
                maxsum=currsum;
                maxlevel=level;
            }
            level++;
            
        }
        return maxlevel;
    }
};