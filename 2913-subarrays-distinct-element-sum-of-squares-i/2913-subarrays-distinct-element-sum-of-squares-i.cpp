class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int sum = 0 ;
        for(int i=0;i<nums.size();i++){
            unordered_map<int,int> mp;
            for(int j =i;j<nums.size();j++){
                mp[nums[j]]++;
                sum+=(mp.size()*mp.size());
            }
        }
        return sum;
    }
};