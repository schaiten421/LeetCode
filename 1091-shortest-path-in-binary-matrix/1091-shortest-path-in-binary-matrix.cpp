class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        queue<pair<int,pair<int,int>>> q;
        if(m==1 && !grid[0][0])return 1;
        if(grid[0][0]==0)q.push({1,{0,0}});
        vector<vector<int>> dist(m,vector<int>(m,1e9));
        dist[0][0]=1;
        while(!q.empty()){
            int len=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if(i==0 && j==0)continue;
                    int r=row+i;
                    int c=col+j;
                    if(r>=0 && r<m && c>=0 && c<m && grid[r][c]==0
                       && 1+dist[row][col]<dist[r][c]){
                        if(r==m-1 && c==m-1) return 1+dist[row][col];
                        dist[r][c]=1+dist[row][col];
                        q.push({dist[r][c],{r,c}});
                    }
                }
            }
            
        }
        return -1;
        
    }
};