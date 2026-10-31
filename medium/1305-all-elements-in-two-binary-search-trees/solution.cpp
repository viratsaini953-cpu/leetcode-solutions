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
    void sortroot1(vector<int>&ans,TreeNode* root){
        if(root==NULL){
            return;
        }
        sortroot1(ans,root->left);
        ans.push_back(root->val);
        sortroot1(ans,root->right);
    }
    void sortroot2(vector<int>&ans,TreeNode* root){
        if(root==NULL){
            return;
        }
        sortroot2(ans,root->left);
        ans.push_back(root->val);
        sortroot2(ans,root->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>ans;
        sortroot1(ans,root1);
        sortroot2(ans,root2);
        sort(ans.begin(),ans.end());
        return ans;
    }
};