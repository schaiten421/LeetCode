class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(row,vector<int>(col,0));
        vector<vector<int>> ans=mat;
        int dist=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},dist});
                    vis[i][j]=1;
                }
            }
        }
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int d=q.front().second;
            q.pop();
            ans[r][c]=d;
            for(int i=0;i<4;i++){
                int nrow=r+dx[i];
                int ncol=c+dy[i];
                if(nrow>=0 && nrow<row && ncol>=0 && ncol<col && vis[nrow][ncol]==0){
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},d+1});
                }
            }   
        }
        return ans;
    }
};