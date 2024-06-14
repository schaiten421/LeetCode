class Solution {
public:
    void bfs(int row,int col,vector<vector<int>> &vis, vector<vector<char>> grid
            ,int di[],int dj[]){
        vis[row][col]=1;
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newrow=r+di[i];
                int newcol=c+dj[i];
                if(newrow>=0 && newcol>=0 && newrow<m && newcol<n && !vis[newrow][newcol] &&
                  grid[newrow][newcol]=='1'){
                    vis[newrow][newcol]=1;
                    q.push({newrow,newcol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        int di[]={0,0,-1,1};
        int dj[]={1,-1,0,0};
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,vis,grid,di,dj);
                }
            }
        }
        return cnt;
    }
};