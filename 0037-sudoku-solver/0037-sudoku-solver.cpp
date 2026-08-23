class Solution {
public:
    bool isValid(int row,int col,char c,vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(board[row][i]==c)return false;
        }
        for(int i=0;i<9;i++){
            if(board[i][col]==c)return false;
        }
        int strow = (row/3)*3;
        int stcol = (col/3)*3;
        for(int i=strow;i<strow+3;i++){
            for(int j=stcol;j<stcol+3;j++){
                if(board[i][j]==c)return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(isValid(i,j,c,board)){
                            board[i][j]=c;
                            if(solve(board))return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};