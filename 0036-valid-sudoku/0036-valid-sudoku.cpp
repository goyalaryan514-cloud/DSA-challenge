class Solution {
public:
    bool isValid(int row,int col,char c,vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(i!=col && board[row][i]==c)return false;
        }
        for(int i=0;i<9;i++){
            if(i!=row && board[i][col]==c)return false;
        }
        int strow = (row/3)*3;
        int stcol = (col/3)*3;
        for(int i=strow;i<strow+3;i++){
            for(int j=stcol;j<stcol+3;j++){
                if((i!=row || j!=col) && board[i][j]==c)return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
       for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (!isValid(i, j, board[i][j], board))
                        return false;
                }
            }  
        }   
        return true;
    }
};