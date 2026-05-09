/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    void dfsS(TreeNode* root,stringstream &ss){
        if(!root){
            ss<<1001;
            ss<<" ";
            return;
        }
        ss<<root->val;
        ss<<" ";
        dfsS(root->left,ss);
        dfsS(root->right,ss);
    }
    TreeNode* dfsDS(stringstream &ss){
        int val;
        ss>>val;
        if(val==1001) return 0;
        TreeNode* root=new TreeNode(val);
        root->left=dfsDS(ss);
        root->right=dfsDS(ss);
        return root;

    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        dfsS(root,ss);
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return dfsDS(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));