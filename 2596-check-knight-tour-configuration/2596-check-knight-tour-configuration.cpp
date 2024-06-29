class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        int di[]={-2,-2,-1,-1,1,1,2,2};
        int dj[]={-1,1,-2,2,-2,2,-1,1};
        queue<pair<int,pair<int,int>>> q;
        vis[0][0]=1;
        q.push({0,{0,0}});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int config=it.first;
            int row=it.second.first;
            int col=it.second.second;
            for(int i=0;i<8;i++){
                int nr=row+di[i];
                int nc=col+dj[i];
                if(nr>=0 &&nr<n &&nc>=0 &&nc<n && !vis[nr][nc] && grid[nr][nc]==config+1){
                    vis[nr][nc]=1;
                    q.push({config+1,{nr,nc}});
                    break;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0)return false;
            }
        }
        return true;
    }
};