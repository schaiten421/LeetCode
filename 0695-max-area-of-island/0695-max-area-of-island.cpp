class Solution {
public:
    void dfs(int row, int col,vector<vector<int>> grid, int &cnt,vector<vector<int>> &vis){
        if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size() || grid[row][col]==0 || vis[row][col]==1)return;
        vis[row][col]=1;
        cnt++;
        dfs(row+1,col,grid,cnt,vis);
        dfs(row-1,col,grid,cnt,vis);
        dfs(row,col+1,grid,cnt,vis);
        dfs(row,col-1,grid,cnt,vis);
        
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        int maxi=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!vis[i][j] && grid[i][j]==1){
                    int cnt=0;
                    dfs(i,j,grid,cnt,vis);
                    maxi=max(maxi,cnt);
                }
            }
        }
        return maxi;
    }
};