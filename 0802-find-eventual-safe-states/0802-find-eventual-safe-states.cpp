class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int m=graph.size();
        vector<int> indegree(m);
        vector<vector<int>> adj(m);
        for(int i=0;i<m;i++){
            for(auto it:graph[i]){
                adj[it].push_back(i);
                indegree[i]++;
            }
        }
        
        
        queue<int> q;
        vector<int> safe;
        for(int i=0;i<m;i++){
            if(!indegree[i])q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            safe.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(!indegree[it])q.push(it);
            }
        }
        sort(safe.begin(),safe.end());
        return safe;
    }
};