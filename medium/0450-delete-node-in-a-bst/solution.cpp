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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        if(key<root->val){
            root->left=deleteNode(root->left,key);
        }
        else if(key>root->val){
            root->right=deleteNode(root->right,key);
        }
        else{
            if(root->left==NULL){
                TreeNode* prev=root->right;
                delete root;
                return prev;
            }
            if(root->right==NULL){
                TreeNode* prev=root->left;
                delete root;
                return prev;
            }

            TreeNode* prev=root->right;
            while(prev->left!=NULL){
                prev=prev->left;
            }

            root->val=prev->val;
            // delete prev;
            root->right=deleteNode(root->right,prev->val);
        }
        return root;
    }
};