class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int n = nums.size();
        long long cnt =0;
        for(int i=0;i<n;i++){
            int mn = INT_MAX;
            int val = -1;
            for(int j=i;j<n;j++){
                mn = min(mn,nums[j]);
                if(i==j){
                    val = nums[j];
                }
                else{
                    val = val&nums[j];
                }
                if(val==mn)cnt++;
            }
        }
        return cnt;
    }
};