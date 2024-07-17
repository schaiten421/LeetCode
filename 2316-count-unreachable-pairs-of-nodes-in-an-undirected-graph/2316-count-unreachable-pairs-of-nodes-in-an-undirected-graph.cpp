class Solution {
public:
    void dfs(vector<int> adj[],vector<int> &vis,int i,int &count){
        vis[i]=1;
        for(auto it:adj[i]){
            if(!vis[it]){
                count++;
                dfs(adj,vis,it,count);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto &it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        vector<int> temp;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int count=1;
                dfs(adj,vis,i,count);
                temp.push_back(count);
            }
        }
        long res=0;
        long tot=0;
        for(int i=0;i<temp.size();i++){
            res+=(long)((long)temp[i]*(long)(n-tot-temp[i]));
            tot+=temp[i];
        }
        return res;
    }
};