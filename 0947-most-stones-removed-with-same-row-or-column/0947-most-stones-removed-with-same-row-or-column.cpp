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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxrow=0;
        int maxcol=0;
        for(auto it:stones){
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }
        DisjointSet ds(maxrow+maxcol+1);
        unordered_map<int,int> stonenodes;
        for(auto it:stones){
            ds.unionbysize(it[0],it[1]+maxrow+1);
            stonenodes[it[0]]=1;
            stonenodes[it[1]+maxrow+1]=1;
        }
        int cnt=0;
        for(auto it:stonenodes){
            if(ds.findPar(it.first)==it.first){
                cnt++;
            }
        }
        return n-cnt;
    }
};