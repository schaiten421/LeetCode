class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(); //1
        int m=matrix[0].size(); //2
        if(n==0 || m==0)return false;
        int low=0,high=n*m-1; //0,1
        while(low<=high){
            int mid=low+(high-low)/2; //0
            int a=mid/m; 
            int b=mid%m;
            if(matrix[a][b]==target) return true;
            else if(matrix[a][b]>target)high=mid-1;
            else low=mid+1;
        }
        return false;
    }
};