class Solution {
public:
    void combination(int last,int target,int k,vector<vector<int>> &ans,vector<int> &nums){
        if(target==0 && nums.size()==k){
            ans.push_back(nums);
            return;
        }
        if(target<=0 || nums.size()>k)return;
        for(int i = last;i<=9;i++){
            if(i<=target){
                nums.push_back(i);
                combination(i+1,target-i,k,ans,nums);
                nums.pop_back();
            }
            else{
                break;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        combination(1,n,k,ans,ds);
        return ans;
    }
};