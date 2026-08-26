class Solution {
public:
    void solve(string num,int target,int index,long long value,long long prev,string exp,vector<string> &ans){
        if(index==num.length()){
            if(value==target){
                ans.push_back(exp);
            }
            return;
        }
        for(int i=index;i<num.length();i++){
            if(i>index && num[index]=='0')break;
            string part = num.substr(index,i-index+1);
            long long curr = stoll(part);
            if(index==0){
                solve(num,target,i+1,curr,curr,part,ans);
            }
            else{
                solve(num,target,i+1,value+curr,curr,exp + '+' + part,ans);
                solve(num,target,i+1,value-curr,-curr,exp + '-' + part,ans);
                solve(num,target,i+1,value - prev + prev*curr,prev*curr,exp +'*'+ part,ans);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        solve(num,target,0,0,0,"",ans);
        return ans;
        
    }
};