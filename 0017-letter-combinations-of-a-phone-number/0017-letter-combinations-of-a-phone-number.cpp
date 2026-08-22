class Solution {
    void solve(string digits,string output,int i,string mapping[],  vector<string>& ans){
        if(i>=digits.length()){
            ans.push_back(output);
            return;
        }
        int n = digits[i] - '0';
        string value = mapping[n];
        for(int x=0;x<value.length();x++){
            output.push_back(value[x]);
            solve(digits,output,i+1,mapping,ans);
            output.pop_back();
        }
        return;
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0){
            return ans;
        }
        string output = "";
        string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,output,0,mapping,ans);
        return ans; 
    }
};