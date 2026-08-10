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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,map<int,multiset<int>>>mpp;
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto [node,cod]=q.front();
            auto [r,c]=cod;
            q.pop();
            mpp[c][r].insert(node->val);
            if(node->left!=nullptr) q.push({node->left,{r+1,c-1}});
            if(node->right!=nullptr) q.push({node->right,{r+1,c+1}});
        }

        for(auto &cols: mpp){
            vector<int>temp;
            for(auto &row: cols.second){
                for(auto &vals : row.second){
                    temp.push_back(vals);
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};