class Solution {
public:
    // bool isSafe(int row,int col,vector<string> temp,int n){
    //     int duprow=row;
    //     int dupcol=col;
    //     while(row>=0 && col>=0){
    //         if(temp[row][col]=='Q')return false;
    //         row--;
    //         col--;
    //     }
    //     row=duprow;col=dupcol;
    //     while(col>=0){
    //         if(temp[row][col]=='Q')return false;
    //         col--;
    //     }
    //     col=dupcol;
    //     while(row<n&& col>=0){
    //         if(temp[row][col]=='Q')return false;
    //         row++;
    //         col--;
    //     }
    //     return true;
    // }
    void f(int col,vector<string> &temp,vector<vector<string>> &ans,int n
          ,vector<int> &leftrow, vector<int> &upperdiag, vector<int> &lowerdiag){
        if(col==n){
            ans.push_back(temp);
            return;
        }
        for(int row=0;row<n;row++){
            if(leftrow[row]==0 && lowerdiag[row+col]==0 && upperdiag[n-1+col-row]==0){
                temp[row][col]='Q';
                leftrow[row]=1;
                lowerdiag[row+col]=1;
                upperdiag[n-1+col-row]=1;
                f(col+1,temp,ans,n,leftrow,upperdiag,lowerdiag);
                temp[row][col]='.';
                leftrow[row]=0;
                lowerdiag[row+col]=0;
                upperdiag[n-1+col-row]=0;
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
        vector<int> leftrow(n,0),upperdiag(2*n-1,0),lowerdiag(2*n-1,0); 
        f(0,temp,ans,n,leftrow,upperdiag,lowerdiag);
        return ans;
        
    }
    
};