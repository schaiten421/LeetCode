class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)return {0};
        vector<int> adj[n];
        vector<int> indegree(n);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[1]]++;
            indegree[edge[0]]++;
        }
        //
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==1){q.push(i);indegree[i]--;}
        }
        while(!q.empty()){
            int s=q.size();
            ans.clear();
            for(int i=0;i<s;i++){
                int node=q.front();q.pop();
                ans.push_back(node);
                for(auto adjnode:adj[node]){
                    indegree[adjnode]--;
                    if(indegree[adjnode]==1)q.push(adjnode);
                }
            }
            
        }
        return ans;
    }
};