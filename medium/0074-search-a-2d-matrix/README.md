# Search a 2D Matrix

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an `m x n` integer matrix `matrix` with the following two properties:

- Each row is sorted in non-decreasing order.
- The first integer of each row is greater than the last integer of the previous row.

Given an integer `target`, return `true` *if* `target` *is in* `matrix` *or* `false` *otherwise*.

You must write a solution in `O(log(m * n))` time complexity.

 

Original
C++
**Example 1:**

```
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

```

**Example 2:**

```
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

```

 

**Constraints:**

- m == matrix.length
- n == matrix[i].length
- 1 <= m, n <= 100
- -104 <= matrix[i][j], target <= 104

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 13.2 MB (beats 91.48%)  
**Submitted:** 2026-11-13T13:58:09.597Z  

```cpp
class Solution {
public:
    bool isSearchTarget(vector<vector<int>>& ma,int target,int mid){
        int n=ma[0].size();
        int s=0,e=n-1;
        while(s<=e){
            int m=s+(e-s)/2;
            if(ma[mid][m]==target){
                return true;
            }
            else if(ma[mid][m]<target){
                s=m+1;;
            }
            else{
                e=m-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& ma, int target) {
        int m=ma.size(), n=ma[0].size();
        int s=0,e=m-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(target>= ma[mid][0] && target <=ma[mid][n-1]){
                return isSearchTarget(ma,target,mid);
            }
            else if(target>= ma[mid][n-1]){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return false;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/search-a-2d-matrix/)