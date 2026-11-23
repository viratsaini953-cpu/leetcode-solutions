# Course Schedule II

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

There are a total of `numCourses` courses you have to take, labeled from `0` to `numCourses - 1`. You are given an array `prerequisites` where `prerequisites[i] = [ai, bi]` indicates that you **must** take course `bi` first if you want to take course `ai`.

- For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

Return *the ordering of courses you should take to finish all courses*. If there are many valid answers, return **any** of them. If it is impossible to finish all courses, return **an empty array**.

 

Original
C++
**Example 1:**

```
Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].

```

**Example 2:**

```
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].

```

**Example 3:**

```
Input: numCourses = 1, prerequisites = []
Output: [0]

```

 

**Constraints:**

- 1 <= numCourses <= 2000
- 0 <= prerequisites.length <= numCourses * (numCourses - 1)
- prerequisites[i].length == 2
- 0 <= ai, bi < numCourses
- ai != bi
- All the pairs [ai, bi] are distinct.

## Solution

**Language:** C++  
**Runtime:** 64 ms (beats 5.05%)  
**Memory:** 17.4 MB (beats 96.91%)  
**Submitted:** 2026-11-23T18:26:34.356Z  

```cpp
class Solution {
public:
    bool dfs(int src,vector<bool>&vis,vector<bool>&recPath,vector<vector<int>>&edge){
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
    void topo(int src,stack<int>&s,vector<bool>&vis,vector<vector<int>>&edge){
        vis[src]=true;
        
        for(int i=0;i<edge.size();i++){
            int u=edge[i][1];
            int v=edge[i][0];
            if(u==src){
                if(!vis[v]){
                    topo(v,s,vis,edge);
                }
            }
        }
        s.push(src);
    
    }
    vector<int> findOrder(int n, vector<vector<int>>&edge){
        vector<bool>vis(n,false);
        vector<bool>recpath(n,false);
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,vis,recpath,edge)){
                    return ans;
                }
            }
        }


        vis.assign(n,false);
        stack<int>s;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                topo(i,s,vis,edge);
            }
        }
        while(!s.empty()){
            int x=s.top();
            s.pop();
            ans.push_back(x);
        }


        return ans;


        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/course-schedule-ii/)