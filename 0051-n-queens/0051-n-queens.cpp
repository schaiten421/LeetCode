class Solution {
public:
    bool isSafe(int row,int col,vector<string> temp,int n){
        int duprow=row;
        int dupcol=col;
        while(row>=0 && col>=0){
            if(temp[row][col]=='Q')return false;
            row--;
            col--;
        }
        row=duprow;col=dupcol;
        while(col>=0){
            if(temp[row][col]=='Q')return false;
            col--;
        }
        col=dupcol;
        while(row<n&& col>=0){
            if(temp[row][col]=='Q')return false;
            row++;
            col--;
        }
        return true;
    }
    void f(int col,vector<string> &temp,vector<vector<string>> &ans,int n){
        if(col==n){
            ans.push_back(temp);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,temp,n)){
                temp[row][col]='Q';
                f(col+1,temp,ans,n);
                temp[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n,'.');
        vector<string> temp;
        for(int i=0;i<n;i++){
            temp.push_back(s);
        }
        f(0,temp,ans,n);
        return ans;
        
    }
};