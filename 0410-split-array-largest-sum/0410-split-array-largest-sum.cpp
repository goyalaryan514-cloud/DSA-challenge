class Solution {
public:
    bool isPossible(vector<int> nums,int n,int k,int mid){
        int stcnt=1;
        int pgsum=0;
        for(int i=0;i<n;i++){
            if(pgsum+nums[i]<=mid){
                pgsum+=nums[i];
            }
            else{
                stcnt++;
                if(stcnt>k || nums[i]>mid){
                    return false;
                }
                pgsum=nums[i];
            }
            if(stcnt>k){
                return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int s=0;
        int e=0;
        for(int i=0;i<n;i++){
            e+=nums[i];
        }
        int ans=-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(isPossible(nums,n,k,mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
        
    }
};