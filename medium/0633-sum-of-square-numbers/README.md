# Sum of Square Numbers

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a non-negative integer `c`, decide whether there're two integers `a` and `b` such that `a2 + b2 = c`.

 

Original
C++
**Example 1:**

```
Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5

```

**Example 2:**

```
Input: c = 3
Output: false

```

 

**Constraints:**

- 0 <= c <= 231 - 1

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 7.9 MB (beats 5.60%)  
**Submitted:** 2026-11-12T15:21:12.635Z  

```cpp
class Solution {
public:
    bool judgeSquareSum(int c) {
        long long i=0;
        long long j=sqrt(c);
        long long sum=0;
        while(i<=j){
            sum=(i*i)+(j*j);
            if(sum==c){
                return true;
            }
            else if(sum>c){
                
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/sum-of-square-numbers/)