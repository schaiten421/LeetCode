class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int> r(grid.size(),0);
        vector<int> c(grid[0].size(),0);
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    r[i]++;
                    c[j]++;
                }
            }
        }
        int cnt=0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int row=it.first;
            int col=it.second;
            if(r[row]>1 || c[col]>1)cnt++;
            
                
        }
        return cnt;
        
    }
};