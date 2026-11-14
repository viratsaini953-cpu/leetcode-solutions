# Valid Mountain Array

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given an array of integers `arr`, return *`true` if and only if it is a valid mountain array*.

Recall that arr is a mountain array if and only if:

- arr.length >= 3
- There exists some i with 0 < i < arr.length - 1 such that: arr[0] < arr[1] < ... < arr[i - 1] < arr[i] arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

 

Original
C++
**Example 1:**

```
Input: arr = [2,1]
Output: false

```

**Example 2:**

```
Input: arr = [3,5,5]
Output: false

```

**Example 3:**

```
Input: arr = [0,3,2,1]
Output: true

```

 

**Constraints:**

- 1 <= arr.length <= 104
- 0 <= arr[i] <= 104

## Solution

**Language:** C++  
**Runtime:** 24 ms (beats 26.80%)  
**Memory:** 26.2 MB (beats 75.27%)  
**Submitted:** 2026-11-14T06:04:40.915Z  

```cpp
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        if(n<3){
            return false;
        }
        int i=0;
        while(i<n-1 && arr[i]<arr[i+1]){
            i++;
        }
        if(i==0 || i==n-1){
            return false;
        }
        while(i<n-1 && arr[i]>arr[i+1]){
            i++;
        }
        if(i==n-1){
            return true;
        }
        else{
            return false;
        }
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/valid-mountain-array/)