/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*>parents;
    //store parent
    void dfs(TreeNode* root){
        if(root==nullptr) return;
        if(root->left!=nullptr)  parents[root->left]=root;
        dfs(root->left);
        if(root->right!=nullptr)  parents[root->right]=root;
        dfs(root->right);
    }

    void bfs(TreeNode* target,int k,vector<int> &res){
        queue<TreeNode*> q;
        q.push(target);
        unordered_set<int>visited;
        visited.insert(target->val);
        while(!q.empty()){
            int n=q.size();
            if(k==0) break;
            while(n--){
                TreeNode* node=q.front();
                q.pop();
                //left
                if(node->left !=nullptr && !visited.count(node->left->val)){
                    q.push(node->left);
                    visited.insert(node->left->val);
                }
                //right
                if(node->right !=nullptr && !visited.count(node->right->val)){
                    q.push(node->right);
                    visited.insert(node->right->val);
                }
                //parent
                 if(parents.count(node) && !visited.count(parents[node]->val)){
                    q.push(parents[node]);
                    visited.insert(parents[node]->val);
                }
            }
            k--;
        }
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            res.push_back(node->val);
        }

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        dfs(root);
        bfs(target,k,res);
        return res;
    }
};