class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>> efforts(m,vector<int>(n,1e9));
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        efforts[0][0]=0;
        pq.push({0,{0,0}});
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        while(!pq.empty()){
            auto it=pq.top();
            int dist=it.first;
            int row=it.second.first;
            int col=it.second.second;
            
            pq.pop();
            if(row==m-1 && col==n-1)return dist;
            for(int i=0;i<4;i++){
                int r=row+dx[i];
                int c=col+dy[i];
                if(r>=0 && r<m && c>=0 && c<n){
                    int effort=max(abs(heights[r][c]-heights[row][col]),dist);
                    if(effort<efforts[r][c]){
                        efforts[r][c]=effort;
                        pq.push({effort,{r,c}});
                    }
                }
            }
            
        }
        return -1;
    }
};