class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = 0;
        for(int i:nums){
            sum+=i;
        }
        int target = sum-x;
        if(target<0){
            return -1;
        }
        int left=0;
        int ws=0;
        int maxlength = -1;
        for(int right=0;right<n;right++){
            ws+=nums[right];
            while(left<=right && ws>target){
                ws-=nums[left];
                left++;
            }
            if(ws==target){
                maxlength = max(maxlength,right-left+1);
            }
        }
        if(maxlength==-1){
            return -1;
        }
        return n-maxlength;
    }
};