class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int a=mat.size(),b=mat[0].size();
        vector<pair<int,int>> v;
        int res=INT_MIN,index;
        for(int i=0;i<a;i++){
            int freq=0;
            for(int j=0;j<b;j++){
                if(mat[i][j]==1){
                   freq++; 
            }
        }
        if(freq>res){
                res=freq;
                index=i;
            }
    }
        return {index,res};
        
}};