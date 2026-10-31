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
    TreeNode* helper(vector<int>&ans,int &i, int bound){
        if(i>=ans.size() || ans[i]>bound){
            return NULL;
        }
        TreeNode* newnode=new TreeNode(ans[i++]);
        newnode->left=helper(ans,i,newnode->val);
        newnode->right=helper(ans,i,bound);
        return newnode;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return helper(preorder, i, INT_MAX);
    }
};