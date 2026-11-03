# Populating Next Right Pointers in Each Node

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a **perfect binary tree** where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

```
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}

```

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to `NULL`.

Initially, all next pointers are set to `NULL`.

 

**Example 1:**

```
Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.

```

**Example 2:**

```
Input: root = []
Output: []

```

 

**Constraints:**

- The number of nodes in the tree is in the range [0, 212 - 1].
- -1000 <= Node.val <= 1000

 

**Follow-up:**

- You may only use constant extra space.
- The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.

## Solution

**Language:** C++  
**Runtime:** 15 ms (beats 50.09%)  
**Memory:** 19.1 MB (beats 65.63%)  
**Submitted:** 2026-11-03T13:28:30.909Z  

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL){
            return root;
        }
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        Node* prev=NULL;
        while(q.size()>0){
            Node* curr=q.front();
            q.pop();
            if(curr==NULL){
                if(q.size()==0){
                    break;
                }
                q.push(NULL);
            }
            else{
                if(curr->left!=NULL){
                    q.push(curr->left);
                    q.push(curr->right);
                }
                if(prev!=NULL){
                    prev->next=curr;
                }
            }
            prev=curr;
        }
        return root;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/)