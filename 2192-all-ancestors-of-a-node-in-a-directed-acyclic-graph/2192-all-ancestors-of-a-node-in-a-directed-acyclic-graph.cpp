class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
        }
        vector<int> indegree(n);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        vector<vector<int>> ans(n);
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                indegree[it]--;
                if(find(ans[it].begin(),ans[it].end(),node)==ans[it].end()){
                    ans[it].push_back(node);
                }
                for(int i=0;i<ans[node].size();i++){
                    if(find(ans[it].begin(),ans[it].end(),ans[node][i])==ans[it].end()){
                        ans[it].push_back(ans[node][i]);
                    }
                }
                if(indegree[it]==0)q.push(it);
            }
        }
        for (int i = 0; i < n; i++)
		{
			sort(ans[i].begin(), ans[i].end());
		}
        return ans;
        }
};

