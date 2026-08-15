class Solution {
public:
    void backtrack(string curr,int open,int close,int n,vector<string> &res){
        if(curr.length()==2*n){
            res.push_back(curr);
            return;
        }
        if(open<n){
            backtrack(curr+'(',open+1,close,n,res);
        }
        if(close<open){
            backtrack(curr+')',open,close+1,n,res);
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr;
        vector<string> res;
        backtrack(curr,0,0,n,res);
        return res;
        
    }
};