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