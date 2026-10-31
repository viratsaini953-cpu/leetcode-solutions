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
    int ans=INT_MAX;
    TreeNode* prev=NULL;
    int getMinimumDifference(TreeNode* root) {
        if(root==NULL){
            return INT_MAX;
        }
        if(root->left!=NULL){
            int leftv=getMinimumDifference(root->left);
            ans=min(ans,leftv);
        }
        if(prev!=NULL){
            ans=min(ans,root->val-prev->val);
        }
        prev=root;
        // ans=min(ans,prev->val-root->val);
        if(root->right!=NULL){
            int rightv=getMinimumDifference(root->right);
            ans=min(ans,rightv);
        }
        return ans;
    }
};