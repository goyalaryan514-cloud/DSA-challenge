class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int i=0,j=n-1;
        int maxL = 0;
        int maxR = n-1;
        int ans=0;
        while(i<=j){
            if(height[i]<=height[j]){
                if(height[i]>=height[maxL]){
                    maxL = i;
                }
                else{
                    ans+=(height[maxL]-height[i]);
                }
                i++;
            }
            else{
                if(height[j]>=height[maxR]){
                    maxR = j;
                }
                else{
                    ans+=(height[maxR]-height[j]);
                }
                j--;
            }
        }
        return ans;
    }
};