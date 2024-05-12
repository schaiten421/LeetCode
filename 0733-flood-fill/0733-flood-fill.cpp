class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color,int inicolor,int delrow[],int delcol[],vector<vector<int>>& ans){
        ans[sr][sc]=color;
        int row=image.size();
        int col=image[0].size();
        for(int i=0;i<4;i++){
            int nrow=sr+delrow[i];
            int ncol=sc+delcol[i];
            if(nrow>=0 && nrow<row && ncol>=0 && ncol<col && image[nrow][ncol]==inicolor && ans[nrow][ncol]!=color){
                dfs(image,nrow,ncol,color,inicolor,delrow,delcol,ans);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor=image[sr][sc];
        vector<vector<int>> ans=image;
        
        int delrow[]={0,0,-1,1};
        int delcol[]={1,-1,0,0};
        dfs(image,sr,sc,color,inicolor,delrow,delcol,ans);
        return ans;
    }
};