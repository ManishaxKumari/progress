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
//morris traversal!!
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res; // to store 
        TreeNode* curr=root; 
        while(curr!=nullptr){
            if(curr->left == nullptr){ //agar left khatam ho jata h tab hi usko store karte h 
                res.push_back(curr->val); // yaha per store kar lo !
                curr=curr->right; // uske right mai chl joa
            }
            else{
                TreeNode* leftchild=curr->left; // ky left child hai?? haai null nhi h exist karta h to phir 
                while(leftchild->right !=nullptr){ // ussi left child ke righmost node mai jao (jab tak vo null ke equal na ho)
                    leftchild=leftchild->right;
                }
                leftchild->right=curr; // jab rightmost mil jayye toh usko curr se connect kar do 
                //curr->left ko NULL mark kar do (delete) kar sakte ho
                TreeNode* temp=curr;
                curr=curr->left;
                temp->left=NULL;
                //purana connection thodna hoga kyuki agar curr dubara pahucha root mai toh or left agar
                //delet nhi hua hoga to dubara left wla call ho jyega !!(ye recursion nhi h isliye)
            }
        }
        return res;

    }
};