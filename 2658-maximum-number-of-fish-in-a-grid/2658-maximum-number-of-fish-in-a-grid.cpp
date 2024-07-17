class Solution {
public:
    void dfs(vector<vector<int>> grid,int i,int j,vector<vector<int>> &vis,int &count){
        vis[i][j]=1;
        count+=grid[i][j];
        int dr[]={0,0,-1,1};
        int dc[]={-1,1,0,0};
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size()
              && !vis[nr][nc] && grid[nr][nc]!=0){
                dfs(grid,nr,nc,vis,count);
            }
        }
        
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int maxi=0;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0 && !vis[i][j]){
                    int count=0;
                    dfs(grid,i,j,vis,count);
                    maxi=max(maxi,count);
                }
            }
        }
        return maxi;
    }
};