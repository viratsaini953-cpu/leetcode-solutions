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