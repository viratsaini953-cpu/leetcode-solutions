# Reverse Linked List II

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given the `head` of a singly linked list and two integers `left` and `right` where `left <= right`, reverse the nodes of the list from position `left` to position `right`, and return *the reversed list*.

 

**Example 1:**

```
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

```

**Example 2:**

```
Input: head = [5], left = 1, right = 1
Output: [5]

```

 

**Constraints:**

- The number of nodes in the list is n.
- 1 <= n <= 500
- -500 <= Node.val <= 500
- 1 <= left <= right <= n

 

**Follow up:** Could you do it in one pass?

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 11.2 MB (beats 61.36%)  
**Submitted:** 2026-11-22T16:39:59.882Z  

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || left == right)
            return head;
        

        ListNode *l=head;
        for(int i=1;i<left-1;i++){
            l=l->next;
        }
        ListNode* lend=l;


        if(left==1){
            l=head;
        }
        else{
            l=l->next;
        }   

        ListNode *r=l;
        for(int j=left;j<right;j++){
            r=r->next;
        }
        ListNode*rend=r->next;;


        ListNode*temp=l;
        ListNode*curr=l;
        ListNode*t=l;
        temp=temp->next;
        
        int k = left;
        while(k<right){
            t=curr;
            curr=temp;
            temp=temp->next;
            curr->next=t;
            k++;
        }
        l->next = rend;
        if(left == 1){
            head = curr;
        }
        else{
            lend->next = curr;
        }
        return head;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/reverse-linked-list-ii/)