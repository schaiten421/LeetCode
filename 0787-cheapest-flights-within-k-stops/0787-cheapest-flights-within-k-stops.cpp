class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it:flights){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
        }
        vector<int> dist(n,1e9);
        dist[src]=0;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        while(!q.empty()){
            auto it=q.front();
            int stops=it.first;
            int city=it.second.first;
            int cost=it.second.second;
            q.pop();
            if(stops>k)continue;
            for(auto iter:adj[city]){
                int adjnode=iter.first;
                int edW=iter.second;
                if(cost+edW<dist[adjnode] && stops<=k){
                    dist[adjnode]=cost+edW;
                    q.push({stops+1,{adjnode,dist[adjnode]}});
                }
            }
        }
        if(dist[dst]==1e9)return -1;
        else return dist[dst];
    }
};