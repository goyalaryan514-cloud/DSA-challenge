class Solution {
public:
    void solve(int col,int n,vector<string> &board,vector<int> &leftrow,vector<int> &upperdig,vector<int> &lowerdig,vector<vector<string>> &ans){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(leftrow[row]==0 && upperdig[n-1+col-row]==0 && lowerdig[row+col]==0){
                board[row][col] = 'Q';
                leftrow[row]=1;
                upperdig[n-1+col-row]=1;
                lowerdig[row+col]=1;
                solve(col+1,n,board,leftrow,upperdig,lowerdig,ans);
                board[row][col] = '.';
                leftrow[row]=0;
                upperdig[n-1+col-row]=0;
                lowerdig[row+col]=0;

            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        vector<int> leftrow(n,0),upperdig(2*n-1,0),lowerdig(2*n-1,0);
        solve(0,n,board,leftrow,upperdig,lowerdig,ans);
        return ans;
    }
};