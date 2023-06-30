class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row=grid.size(),column=grid[0].size();
        int i=row-1,j=0,result=0;
        if(grid[row-1][column-1]>=0)return 0;
        while(i>=0 && j<=column-1){
            if(grid[i][j]<0){
                result+=column-j;
                i--;}
            else
            {j++;}
                
        }
        return result;
    }
};