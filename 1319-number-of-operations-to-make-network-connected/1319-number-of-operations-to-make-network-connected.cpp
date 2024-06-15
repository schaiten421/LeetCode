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
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extraedges=0;
        for(auto it:connections){
            if(ds.findPar(it[0])==ds.findPar(it[1])){
                extraedges++;
            }
            else{
                ds.unionbysize(it[0],it[1]);
            }
        }
        int cntC=0;
        for(int i=0;i<n;i++){
            if(ds.findPar(i)==i)cntC++;
        }
        int ans=cntC-1;
        if(extraedges>=ans)return ans;
        else return -1;
    }
};