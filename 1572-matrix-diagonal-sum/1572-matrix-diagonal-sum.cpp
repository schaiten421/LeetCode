class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int m=mat.size(),result=0;;
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(i==j)result+=mat[i][j];
                if(i+j==(m-1) && i!=j)result+=mat[i][j];
            }
        }
        return result;
    }
};