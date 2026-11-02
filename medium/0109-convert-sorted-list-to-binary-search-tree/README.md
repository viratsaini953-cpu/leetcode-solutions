# Convert Sorted List to Binary Search Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given the `head` of a singly linked list where elements are sorted in **ascending order**, convert *it to a ****height-balanced*** *binary search tree*.

 

**Example 1:**

```
Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.

```

**Example 2:**

```
Input: head = []
Output: []

```

 

**Constraints:**

- The number of nodes in head is in the range [0, 2 * 104].
- -105 <= Node.val <= 105

## Solution

**Language:** C++  
**Runtime:** 378 ms (beats 6.91%)  
**Memory:** 366 MB (beats 10.86%)  
**Submitted:** 2026-11-02T09:20:58.783Z  

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* build(vector<int>arr,int l, int h){
        if(l>h){
            return NULL;
        }
        int mid=l+(h-l)/2;
        TreeNode* root=new TreeNode(arr[mid]);
        root->left=build(arr,l,mid-1);
        root->right=build(arr,mid+1,h);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head){
        vector<int>arr;
        ListNode* temp=head;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int low=0;
        int high=arr.size()-1;
        return build(arr,low,high);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/)