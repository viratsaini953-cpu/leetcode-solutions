# Valid Parentheses

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:

- Open brackets must be closed by the same type of brackets.
- Open brackets must be closed in the correct order.
- Every close bracket has a corresponding open bracket of the same type.

 

**Example 1:**

**Input:** s = "()"

**Output:** true

**Example 2:**

**Input:** s = "()[]{}"

**Output:** true

**Example 3:**

**Input:** s = "(]"

**Output:** false

**Example 4:**

**Input:** s = "([])"

**Output:** true

**Example 5:**

**Input:** s = "([)]"

**Output:** false

 

**Constraints:**

- 1 <= s.length <= 104
- s consists of parentheses only '()[]{}'.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 8.8 MB (beats 82.26%)  
**Submitted:** 2026-11-04T04:51:10.462Z  

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char>s1;
        int n=s.length();
        for(char ch: s){
            if(ch=='{' || ch=='(' || ch=='['){
                s1.push(ch);
            }
            else{
                if(s1.empty()){
                    return false;
                }
                if(ch=='}' && s1.top() != '{'){
                    return false;
                }
                if(ch==')' &&  s1.top()!='('){
                    return false;
                }
                if(ch==']' && s1.top()!='['){
                    return false;
                }
                s1.pop();
            }
        }
        return s1.empty();
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/valid-parentheses/)