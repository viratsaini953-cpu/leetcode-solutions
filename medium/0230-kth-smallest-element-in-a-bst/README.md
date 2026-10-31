# Kth Smallest Element in a BST

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given the `root` of a binary search tree, and an integer `k`, return *the* `kth` *smallest value (**1-indexed**) of all the values of the nodes in the tree*.

 

**Example 1:**

```
Input: root = [3,1,4,null,2], k = 1
Output: 1

```

**Example 2:**

```
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3

```

 

**Constraints:**

- The number of nodes in the tree is n.
- 1 <= k <= n <= 104
- 0 <= Node.val <= 104

 

**Follow up:** If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 24.4 MB (beats 50.15%)  
**Submitted:** 2026-10-31T05:25:07.844Z  

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
    int sum=0;
    int ans=-1;
    void inorder(TreeNode* root,int k){
        if(root==NULL){
            return ;
        }
        inorder(root->left,k);
        sum++;
        if(sum==k){
            ans=root->val;
            return;
        }
        inorder(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)