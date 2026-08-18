class Solution {
public:
    void backtrack(int ind,vector<int>& nums,vector<vector<int>> &result,vector<int> &current){
        result.push_back(current);
        for(int i = ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1])continue;
            current.push_back(nums[i]);
            backtrack(i+1,nums,result,current);
            current.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int> current;
        backtrack(0,nums,result,current);
        return result;
    }
};