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
    unordered_map<int, int> inorderMap;
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,
                    int start, int end, int &index) {
        if (start > end) return nullptr;
        int rootval = postorder[index--];
        int i=inorderMap[rootval];
        TreeNode* root = new TreeNode(rootval);
        root->right = solve(inorder, postorder, i + 1, end, index);
        root->left = solve(inorder, postorder, start, i - 1, index);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index = postorder.size() - 1;
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        return solve(inorder, postorder, 0, inorder.size() - 1, index);
    }
};