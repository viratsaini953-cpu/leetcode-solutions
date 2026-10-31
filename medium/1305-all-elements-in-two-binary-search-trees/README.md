# All Elements in Two Binary Search Trees

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given two binary search trees `root1` and `root2`, return *a list containing all the integers from both trees sorted in **ascending** order*.

 

**Example 1:**

```
Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]

```

**Example 2:**

```
Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]

```

 

**Constraints:**

- The number of nodes in each tree is in the range [0, 5000].
- -105 <= Node.val <= 105

## Solution

**Language:** C++  
**Runtime:** 12 ms (beats 24.97%)  
**Memory:** 86.2 MB (beats 89.71%)  
**Submitted:** 2026-10-31T06:03:06.845Z  

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
```

---

[View on LeetCode](https://leetcode.com/problems/all-elements-in-two-binary-search-trees/)