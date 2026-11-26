# Symmetric Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given the `root` of a binary tree, *check whether it is a mirror of itself* (i.e., symmetric around its center).

 

**Example 1:**

```
Input: root = [1,2,2,3,4,4,3]
Output: true

```

**Example 2:**

```
Input: root = [1,2,2,null,3,null,3]
Output: false

```

 

**Constraints:**

- The number of nodes in the tree is in the range [1, 1000].
- -100 <= Node.val <= 100

 

**Follow up:** Could you solve it both recursively and iteratively?

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 18.4 MB (beats 82.02%)  
**Submitted:** 2026-11-26T10:22:56.035Z  

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
    bool check(TreeNode* left,TreeNode* right){
        if(left==NULL && right==NULL){
            return true;
        }
        if(left==NULL || right==NULL){
            return false;
        }
        if(left->val!=right->val){
            return false;
        }
        return check(left->left, right->right)&& check(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        return check(root->left,root->right);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/symmetric-tree/)