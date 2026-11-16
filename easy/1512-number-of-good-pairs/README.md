# Number of Good Pairs

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given an array of integers `nums`, return *the number of **good pairs***.

A pair `(i, j)` is called *good* if `nums[i] == nums[j]` and `i` < `j`.

 

Original
C++
**Example 1:**

```
Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.

```

**Example 2:**

```
Input: nums = [1,1,1,1]
Output: 6
Explanation: Each pair in the array are good.

```

**Example 3:**

```
Input: nums = [1,2,3]
Output: 0

```

 

**Constraints:**

- 1 <= nums.length <= 100
- 1 <= nums[i] <= 100

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 9.7 MB (beats 58.29%)  
**Submitted:** 2026-11-16T01:38:15.809Z  

```cpp
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n =nums.size();
        int c=0;
        for(int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                if(nums[i]==nums[j]){
                    c++;
                }
            }
        }
        return c;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/number-of-good-pairs/)