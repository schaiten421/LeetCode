class Solution {
public:
    void dfs(int node,vector<vector<int>> graph,vector<int> &temp,vector<vector<int>> &ans){
        if(node==graph.size()-1){
            ans.push_back(temp);
        }
        for(auto it:graph[node]){
            temp.push_back(it);
            dfs(it,graph,temp,ans);
        }
        temp.pop_back();
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> temp;
        temp.push_back(0);
        dfs(0,graph,temp,ans);
        return ans;
        
        
        
    }
};