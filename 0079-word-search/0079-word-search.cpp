class Solution {
public:
    bool solve(int nexti,int nextj,int ind,vector<vector<char>> &board,string word){
        if(ind==word.length()){
            return true;
        }
        if(nexti<0 || nextj<0 || nexti>=board.size() || nextj>=board[0].size() ||
             word[ind]!=board[nexti][nextj])return false;
        
        board[nexti][nextj]=' ';
        if(solve(nexti+1,nextj,ind+1,board,word) ||
          solve(nexti-1,nextj,ind+1,board,word) ||
          solve(nexti,nextj+1,ind+1,board,word) ||
          solve(nexti,nextj-1,ind+1,board,word))return true;
        board[nexti][nextj]=word[ind];
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    if(solve(i,j,0,board,word))return true;
                }
            }
        }
        return false;
        
    }
};