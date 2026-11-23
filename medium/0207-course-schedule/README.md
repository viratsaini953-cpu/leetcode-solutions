# Course Schedule

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

There are a total of `numCourses` courses you have to take, labeled from `0` to `numCourses - 1`. You are given an array `prerequisites` where `prerequisites[i] = [ai, bi]` indicates that you **must** take course `bi` first if you want to take course `ai`.

- For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

Return `true` if you can finish all courses. Otherwise, return `false`.

 

Original
C++
**Example 1:**

```
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

```

**Example 2:**

```
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

```

 

**Constraints:**

- 1 <= numCourses <= 2000
- 0 <= prerequisites.length <= 5000
- prerequisites[i].length == 2
- 0 <= ai, bi < numCourses
- All the pairs prerequisites[i] are unique.

## Solution

**Language:** C++  
**Runtime:** 62 ms (beats 5.01%)  
**Memory:** 17.6 MB (beats 99.52%)  
**Submitted:** 2026-11-23T17:50:05.692Z  

```cpp
class Solution {
public:
    bool dfs(int src,vector<bool>& vis,vector<bool>& recPath,vector<vector<int>>&edge){
        vis[src]=true;
        recPath[src]=true;
        for(int i=0;i<edge.size();i++){
            int u=edge[i][1];
            int v=edge[i][0];
            if(u==src){
                if(!vis[v]){
                    if(dfs(v,vis,recPath,edge)){
                        return true;
                    }
                }else if(recPath[v]){
                    return true;
                }

            }

        }
        recPath[src]=false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& edge) {
        vector<bool>vis(n,false);
        vector<bool>recPath(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,vis,recPath,edge)){
                    return false;
                }
            }
        }
        return true;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/course-schedule/)