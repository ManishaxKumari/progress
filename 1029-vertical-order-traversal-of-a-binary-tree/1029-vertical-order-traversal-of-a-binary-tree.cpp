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
        vector<vector<int>> res;
        if(root==nullptr){
            return res;
        }
        //map->vertical->store diff level->asecending order mai nodes in same level and same vertices
        map<int,map<int,priority_queue<int,vector<int>,greater<int>>>>nodesmap;

        //queue for bfs traversal
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root, {0, 0}});
        //perform bfs
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            TreeNode* node = p.first;
            int x=p.second.first;
            int y=p.second.second;
            nodesmap[x][y].push(node->val);
            if(node->left !=nullptr){
                q.push({node->left,{x-1,y+1}});
            }
            if(node->right !=nullptr){
                q.push({node->right,{x+1,y+1}});
            }
        }
        //Prepare result
        for( auto &p:nodesmap){
            vector<int>col;
           for (auto& q : p.second) {
                while (!q.second.empty()) {
                    col.push_back(q.second.top());
                    q.second.pop();
                }
            }
            res.push_back(col);
        }
        return res;
    }
};