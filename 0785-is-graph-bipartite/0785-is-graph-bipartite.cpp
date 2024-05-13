class Solution {
public:
    bool f(int i,int vis[],vector<vector<int>>& graph){
        vis[i]=0;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it: graph[node]){
                if(vis[it]==-1){
                    vis[it]=!vis[node];
                    q.push(it);
                }
                else if(vis[it]==vis[node]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int m=graph.size();
        int vis[m];
        for(int i=0;i<m;i++)vis[i]=-1;
        for(int i=0;i<m;i++){
            if(vis[i]==-1){
                if(f(i,vis,graph)==false)return false;
            }
        }
        return true;
        
    }
};