# Delete Node in a BST

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return *the **root node reference** (possibly updated) of the BST*.

Basically, the deletion can be divided into two stages:

- Search for a node to remove.
- If the node is found, delete the node.

 

**Example 1:**

```
Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

```

**Example 2:**

```
Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.

```

**Example 3:**

```
Input: root = [], key = 0
Output: []

```

 

**Constraints:**

- The number of nodes in the tree is in the range [0, 104].
- -105 <= Node.val <= 105
- Each node has a unique value.
- root is a valid binary search tree.
- -105 <= key <= 105

 

**Follow up:** Could you solve it with time complexity `O(height of tree)`?

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 34.3 MB (beats 81.59%)  
**Submitted:** 2026-11-04T05:34:21.878Z  

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        if(key<root->val){
            root->left=deleteNode(root->left,key);
        }
        else if(key>root->val){
            root->right=deleteNode(root->right,key);
        }
        else{
            if(root->left==NULL){
                TreeNode* prev=root->right;
                delete root;
                return prev;
            }
            if(root->right==NULL){
                TreeNode* prev=root->left;
                delete root;
                return prev;
            }

            TreeNode* prev=root->right;
            while(prev->left!=NULL){
                prev=prev->left;
            }

            root->val=prev->val;
            // delete prev;
            root->right=deleteNode(root->right,prev->val);
        }
        return root;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/delete-node-in-a-bst/)