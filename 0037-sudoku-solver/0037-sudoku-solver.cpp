class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char ch='1';ch<='9';ch++){
                        if(isValid(board,i,j,ch)){
                            board[i][j]=ch;
                            if(solve(board)==true){
                                return true;
                            }
                            else board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isValid(vector<vector<char>>& board,int i, int j,char ch ){
        for(int k=0;k<9;k++){
            if(board[k][j]==ch)return false;
            if(board[i][k]==ch)return false;
            if(board[3*(i/3)+k/3][3*(j/3)+k%3]==ch)return false;
            
        }
        return true;
    }
};