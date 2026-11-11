class Solution {
public:
    void solve(vector<int> nums,vector<vector<int>>& ans,int i){
        if(i>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int x=i;x<nums.size();x++){
            swap(nums[i],nums[x]);
            solve(nums,ans,i+1);
            swap(nums[i],nums[x]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums,ans,0);
        return ans;
    }
};