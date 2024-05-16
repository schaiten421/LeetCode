class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it: times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n+1,1e9);
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>>> pq;
        pq.push({0,k});
        
        while(!pq.empty()){
            auto it=pq.top();
            int time=it.first;
            int node=it.second;
            pq.pop();
            for(auto iter:adj[node]){
                int adjnode=iter.first;
                int edW=iter.second;
                if(time+edW<dist[adjnode]){
                    dist[adjnode]=time+edW;
                    pq.push({time+edW,adjnode});
                }
            }
        }
        int maxi=-1e9;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9)return -1;
            else maxi=max(maxi,dist[i]);  
        }
        return maxi;
    }
};