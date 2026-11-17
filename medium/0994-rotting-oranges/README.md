# Rotting Oranges

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an `m x n` `grid` where each cell can have one of three values:

- 0 representing an empty cell,
- 1 representing a fresh orange, or
- 2 representing a rotten orange.

Every minute, any fresh orange that is **4-directionally adjacent** to a rotten orange becomes rotten.

Return *the minimum number of minutes that must elapse until no cell has a fresh orange*. If *this is impossible, return* `-1`.

 

Original
C++
**Example 1:**

```
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

```

**Example 2:**

```
Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

```

**Example 3:**

```
Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

```

 

**Constraints:**

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 10
- grid[i][j] is 0, 1, or 2.

## Solution

**Language:** C++  
**Runtime:** 2 ms (beats 35.43%)  
**Memory:** 17.2 MB (beats 22.61%)  
**Submitted:** 2026-11-17T13:42:59.267Z  

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }
        while(q.size()>0){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int time=q.front().second;
            q.pop();
            ans=max(ans,time);

            if(i-1>=0 && !vis[i-1][j] && grid[i-1][j]==1){
                q.push({{i-1,j},time+1});
                vis[i-1][j]=true;
            }
            if(j+1<m && !vis[i][j+1] && grid[i][j+1]==1){
                q.push({{i,j+1},time+1});
                vis[i][j+1]=true;
            }
            if(i+1<n && !vis[i+1][j] && grid[i+1][j]==1){
                q.push({{i+1,j},time+1});
                vis[i+1][j]=true;
            }
            if(j-1>=0 && !vis[i][j-1] && grid[i][j-1]==1){
                q.push({{i,j-1},time+1});
                vis[i][j-1]=true;
            }


        }
        for(int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    return -1;
                }
            }
        }
        return ans;

    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/rotting-oranges/)