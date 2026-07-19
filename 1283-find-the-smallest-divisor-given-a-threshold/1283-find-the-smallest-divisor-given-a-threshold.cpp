class Solution {
public:
    int SumBy(vector<int> nums,int div){
        int n = nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum += ceil((double)nums[i]/div);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n= nums.size();
        int s=1;
        int e = *max_element(nums.begin(),nums.end());
        while(s<=e){
            int mid=s+(e-s)/2;
            if(SumBy(nums,mid)<=threshold){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return s;
        
    }
};