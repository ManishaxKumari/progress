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
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto [node,cor]=q.front();
            auto [r,c]=cor;
            q.pop();
            nodes[c][r].insert(node->val);
            if(node->left!=nullptr) q.push({node->left,{r+1,c-1}});
            if(node->right!=nullptr) q.push({node->right,{r+1,c+1}});
        }

        for(auto cols:nodes){
            vector<int>temp;
            for(auto rows: cols.second){
                for(auto vals: rows.second ){
                    temp.push_back(vals);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};