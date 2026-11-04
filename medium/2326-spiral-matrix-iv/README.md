# Spiral Matrix IV

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given two integers `m` and `n`, which represent the dimensions of a matrix.

You are also given the `head` of a linked list of integers.

Generate an `m x n` matrix that contains the integers in the linked list presented in **spiral** order **(clockwise)**, starting from the **top-left** of the matrix. If there are remaining empty spaces, fill them with `-1`.

Return *the generated matrix*.

 

**Example 1:**

```
Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
Output: [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
Explanation: The diagram above shows how the values are printed in the matrix.
Note that the remaining spaces in the matrix are filled with -1.

```

**Example 2:**

```
Input: m = 1, n = 4, head = [0,1,2]
Output: [[0,1,2,-1]]
Explanation: The diagram above shows how the values are printed from left to right in the matrix.
The last space in the matrix is set to -1.
```

 

**Constraints:**

- 1 <= m, n <= 105
- 1 <= m * n <= 105
- The number of nodes in the list is in the range [1, m * n].
- 0 <= Node.val <= 1000

## Solution

**Language:** C++  
**Runtime:** 24 ms (beats 37.59%)  
**Memory:** 138.2 MB (beats 25.83%)  
**Submitted:** 2026-11-04T20:25:25.234Z  

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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int sr=0;
        int er=m-1;
        int sc=0;
        int ec=n-1;
        ListNode* temp=head;
        while(temp!=NULL && sr <= er && sc <= ec){
            //top
            for(int i=sc;i<=ec && temp != NULL;i++){
                ans[sr][i]=temp->val;
                temp=temp->next;
            }

            // right
            for(int i=sr+1;i<=er && temp != NULL;i++){
                ans[i][ec]=temp->val;
                temp=temp->next;
            }

            for(int i=ec-1;i>=sc && sr<er && temp != NULL;i--){
                ans[er][i]=temp->val;
                temp=temp->next;
            }

            for(int i=er-1;i>sr&& sc<ec && temp != NULL;i--){
                ans[i][sc]=temp->val;
                temp=temp->next;
            }
            ec--;
            sc++;
            er--;
            sr++;
        }
    return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/spiral-matrix-iv/)