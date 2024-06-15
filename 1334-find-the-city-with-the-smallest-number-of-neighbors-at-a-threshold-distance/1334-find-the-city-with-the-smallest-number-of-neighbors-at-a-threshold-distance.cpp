class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        vector<vector<int>> adjmatrix(n,vector<int>(n,1e9));
        for(auto it:edges){
            adjmatrix[it[0]][it[1]]=it[2];
            adjmatrix[it[1]][it[0]]=it[2];
        }
        for(int i=0;i<n;i++){
            adjmatrix[i][i]=0;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    adjmatrix[i][j]=min(adjmatrix[i][k]+adjmatrix[k][j],adjmatrix[i][j]);
                }
            }
        }
        int city=0,othercities=0;
        for(int i=0;i<n;i++){
            int cities=0;
            for(int j=0;j<n;j++){
                if(adjmatrix[i][j]<=k){
                    cities++;
                }
            }
            if(cities<=othercities ||  i==0){
                othercities=cities;
                city=i;
            }
        }
        return city;
    }
};