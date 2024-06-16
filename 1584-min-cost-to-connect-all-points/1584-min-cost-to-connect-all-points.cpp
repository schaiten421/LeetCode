class DisjointSet{
    public:
    vector<int> rank,parent,size;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findPar(int node){
        if(node==parent[node])return node;
        return parent[node]=findPar(parent[node]);
    }
    void unionbyrank(int u,int v){
        int par_u=findPar(u);
        int par_v=findPar(v);
        if(par_u==par_v)return;
        if(rank[par_u]<rank[par_v]){
            parent[par_u]=par_v;
        }
        else if(rank[par_v]<rank[par_u]){
            parent[par_v]=par_u;
        }
        else{
            parent[par_u]=par_v;
            rank[par_v]++;
        }
    }
    void unionbysize(int u,int v){
        int par_u=findPar(u);
        int par_v=findPar(v);
        if(par_u==par_v)return;
        if(size[par_u]<size[par_v]){
            parent[par_u]=par_v;
            size[par_v]+=size[par_u];
        }
        else{
            parent[par_v]=par_u;
            size[par_u]+=size[par_v];
        }
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<points.size();i++){
            for(int j=0;j<points.size();j++){
                if(i==j)continue;
                int wt=abs(points[j][1]-points[i][1])+abs(points[j][0]-points[i][0]);
                edges.push_back({wt,{i,j}});
            }
        }
        DisjointSet ds(points.size());
        sort(edges.begin(),edges.end());
        int mstwt=0;
        for(auto it:edges){
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            if(ds.findPar(u)!=ds.findPar(v)){
                mstwt+=wt;
                ds.unionbysize(u,v);
            }
            
        }
        return mstwt;
    }
};