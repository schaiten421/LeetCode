class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<n;i++){
            int a=prerequisites[i][1];
            int b=prerequisites[i][0];
            adj[a].push_back(b);
        }
        int indegree[numCourses];
        for(int i=0;i<numCourses;i++)indegree[i]=0;
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(!indegree[i])q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        if(topo.size()==numCourses)return true;
        else return false;
    }
};