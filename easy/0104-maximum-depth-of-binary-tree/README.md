# Maximum Depth of Binary Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given the `root` of a binary tree, return *its maximum depth*.

A binary tree's **maximum depth** is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

**Example 1:**

```
Input: root = [3,9,20,null,null,15,7]
Output: 3

```

**Example 2:**

```
Input: root = [1,null,2]
Output: 2

```

 

**Constraints:**

- The number of nodes in the tree is in the range [0, 104].
- -100 <= Node.val <= 100

## Solution

**Language:** C++  
**Runtime:** 1 ms (beats 19.29%)  
**Memory:** 22.3 MB (beats 19.56%)  
**Submitted:** 2026-11-26T09:58:12.848Z  

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
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL){
            return maxDepth(root->right)+1;
        }
        if(root->right==NULL){
            return maxDepth(root->left)+1;
        }
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-depth-of-binary-tree/)