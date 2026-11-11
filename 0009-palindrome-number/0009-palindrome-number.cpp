class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        else{
            vector<int> nums;
            while(x>0){
                nums.push_back(x%10);
                x=x/10;
            }
            int left=0;
            int right = nums.size()-1;
            while(left<right){
                if(nums[left]!=nums[right])return false;
                left++;
                right--;
            }
            return true;
        }
        
    }
};