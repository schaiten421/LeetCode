class Solution {
public:
    vector<vector<int>> graph;
    vector<vector<int>> revgraph;
    map<pair<int,int>,int> dp;
    
    int dfs(int node,int parent){
        int ans=0;
        
        if(dp.find({node, parent}) != dp.end())
            return dp[{node, parent}];
        
        for(auto &it:graph[node]){
            if(it!=parent)
                ans+=dfs(it,node);
        }
        for(auto &it:revgraph[node]){
            if(it!=parent)
                ans+=dfs(it,node)+1;
        }
        return dp[{node,parent}]=ans;
    }
    
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        graph=vector<vector<int>>(n);
        revgraph=vector<vector<int>>(n);
        
        for(auto it:edges){
            graph[it[0]].push_back(it[1]);
            revgraph[it[1]].push_back(it[0]);
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(dfs(i,-1));
        }
        return ans;
    }
};