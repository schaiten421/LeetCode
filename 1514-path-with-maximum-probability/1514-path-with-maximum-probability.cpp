class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double> prob(n,(double)0.0);
        prob[start]=1.0;
        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            double nodeprob=it.first;
            int node=it.second;
            for(auto iter:adj[node]){
                int adjnode=iter.first;
                double adjprob=iter.second;
                if(nodeprob*adjprob>prob[adjnode]){
                    prob[adjnode]=nodeprob*adjprob;
                    pq.push({nodeprob*adjprob,adjnode});
                }
            }
        }
        return prob[end];
    }
};