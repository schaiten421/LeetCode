class Solution {
public:
    int check(vector<vector<int>> mat,int mid,int m){
        int maxi=INT_MIN,index=-1;
        for(int i=0;i<m;i++){
            if(mat[i][mid]>maxi){
                maxi=mat[i][mid];
                index=i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int index=check(mat,mid,m);
            int left=(mid-1>=0)?mat[index][mid-1]:-1;
            int right=(mid+1<n)?mat[index][mid+1]:-1;
            if(mat[index][mid]>left && mat[index][mid]>right){
                return {index,mid};
            }
            else if(mat[index][mid]<left)high=mid-1;
            else low=mid+1;
        }
        return {-1,-1};
    }
};