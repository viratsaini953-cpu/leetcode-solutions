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
int sum=0;
    int sumOfLeftLeaves(TreeNode* root) {
        queue<TreeNode*>q;
        if(root==NULL){
            return 0;
        }
        q.push(root);
        int sum=0;
        while(q.size()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left!=NULL){
                if (curr->left->left == NULL &&
                    curr->left->right == NULL) {
                    sum += curr->left->val;
                } else {
                    q.push(curr->left);
                }
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
        return sum;
    }
};