class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        int ans1=-1;
        int ans2=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(target==nums[mid]){
                ans1=mid;
                e=mid-1;
            }
            else if(nums[mid]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        s=0;
        e=nums.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(target==nums[mid]){
                ans2=mid;
                s=mid+1;
            }
            else if(nums[mid]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        vector<int> ans;
        
            ans.push_back(ans1);
            ans.push_back(ans2);

        
        return ans;

        
        
    }
};