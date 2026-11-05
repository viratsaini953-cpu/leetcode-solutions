# 3Sum Closest

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an integer array `nums` of length `n` and an integer `target`.

Find three integers at **distinct indices** in `nums` such that the sum is **closest** to `target`.

Return the sum of the three integers.

You may assume that each input would have **exactly** one solution.

 

**Example 1:**

```
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

```

**Example 2:**

```
Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).

```

 

**Constraints:**

- 3 <= nums.length <= 500
- -1000 <= nums[i] <= 1000
- -104 <= target <= 104

## Solution

**Language:** C++  
**Runtime:** 9 ms (beats 74.94%)  
**Memory:** 14 MB (beats 45.57%)  
**Submitted:** 2026-11-05T20:57:06.611Z  

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums,int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int d=INT_MAX;
        int c=INT_MIN;
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<target){
                    c=max(c,sum);
                    j++;
                }
                else if(sum>target)
                {
                    d=min(d,sum);
                    k--;
                }
                else{
                    return sum;
                }
            }
        }
        if(d==INT_MAX){
            return c;
        }
        if(c==INT_MIN){
            return d;
        }
        int s = abs(d - target);
        int v = abs(c - target);
        if(s<v){
            return d;
        }
        return c;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/3sum-closest/)