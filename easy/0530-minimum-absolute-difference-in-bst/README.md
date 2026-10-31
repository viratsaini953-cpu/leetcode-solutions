# Minimum Absolute Difference in BST

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given the `root` of a Binary Search Tree (BST), return *the minimum absolute difference between the values of any two different nodes in the tree*.

 

**Example 1:**

```
Input: root = [4,2,6,1,3]
Output: 1

```

**Example 2:**

```
Input: root = [1,0,48,null,null,12,49]
Output: 1

```

 

**Constraints:**

- The number of nodes in the tree is in the range [2, 104].
- 0 <= Node.val <= 105

 

**Note:** This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 25.5 MB (beats 63.61%)  
**Submitted:** 2026-10-31T04:25:02.510Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-absolute-difference-in-bst/)