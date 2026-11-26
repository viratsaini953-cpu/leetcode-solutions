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
    int sum = 0;

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return false;
        }

        sum += root->val;

        if(root->left == NULL && root->right == NULL){
            bool ans=false;;
            if(sum==targetSum){
                ans=true;
            }
            sum -= root->val;
            return ans;
        }

        bool left = hasPathSum(root->left, targetSum);
        bool right = hasPathSum(root->right, targetSum);

        sum -= root->val;

        return left || right;
    }
};