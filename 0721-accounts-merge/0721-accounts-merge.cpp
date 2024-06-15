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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int> mpp;
        DisjointSet ds(accounts.size());
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mpp.find(accounts[i][j])==mpp.end()){
                    mpp[accounts[i][j]]=i;
                }
                else{
                    ds.unionbysize(i,mpp[accounts[i][j]]);
                }
            }
        }
        vector<string> mergedmail[accounts.size()];
        for(auto it:mpp){
            string mail=it.first;
            int node=ds.findPar(it.second);
            mergedmail[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i=0;i<accounts.size();i++){
            if(mergedmail[i].size()==0)continue;
            sort(mergedmail[i].begin(),mergedmail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it: mergedmail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};