class Solution {
public:
    int countAtMost(vector<int>& nums, int k){
        int n = nums.size();
        int left = 0;
        int oddcount=0;
        int count=0;
        for(int right=0;right<n;right++){
            if(nums[right]%2!=0){
                oddcount++;
            }
            while(oddcount>k){
                if(nums[left]%2!=0){
                    oddcount--;
                }
                left++;
            }
            count+=right-left+1;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return countAtMost(nums, k) - countAtMost(nums, k - 1);
    }
};