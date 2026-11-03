# Merge Nodes in Between Zeros

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given the `head` of a linked list, which contains a series of integers **separated** by `0`'s. The **beginning** and **end** of the linked list will have `Node.val == 0`.

For **every **two consecutive `0`'s, **merge** all the nodes lying in between them into a single node whose value is the **sum** of all the merged nodes. The modified list should not contain any `0`'s.

Return *the* `head` *of the modified linked list*.

 

**Example 1:**

```
Input: head = [0,3,1,0,4,5,2,0]
Output: [4,11]
Explanation: 
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 3 + 1 = 4.
- The sum of the nodes marked in red: 4 + 5 + 2 = 11.

```

**Example 2:**

```
Input: head = [0,1,0,3,0,2,2,0]
Output: [1,3,4]
Explanation: 
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 1 = 1.
- The sum of the nodes marked in red: 3 = 3.
- The sum of the nodes marked in yellow: 2 + 2 = 4.

```

 

**Constraints:**

- The number of nodes in the list is in the range [3, 2 * 105].
- 0 <= Node.val <= 1000
- There are no two consecutive nodes with Node.val == 0.
- The beginning and end of the linked list have Node.val == 0.

## Solution

**Language:** C++  
**Runtime:** 69 ms (beats 14.37%)  
**Memory:** 295 MB (beats 47.94%)  
**Submitted:** 2026-11-03T17:00:05.484Z  

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
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp=head;
        int c=0;
        ListNode* head1 = NULL;
        ListNode* tail = NULL;
        head1=NULL;
        while(temp!=NULL){
            if(temp->val==0){
                if(c){
                    ListNode* newnode=new ListNode(c);
                    if (head1 == NULL) {
                        head1 = newnode;
                        tail = newnode;
                    }
                    else {
                        tail->next = newnode;
                        tail = newnode;
                    }
                }
                c=0;
            }
            else{
                c+=temp->val;
            }
            temp=temp->next;
        }
        return head1;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/merge-nodes-in-between-zeros/)