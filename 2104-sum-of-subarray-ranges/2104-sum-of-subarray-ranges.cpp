class Solution {
public:
    vector<int> findNse(vector<int> &nums){
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            ans[i] = !st.empty() ? st.top():n;
            st.push(i);
        }
        return ans;
    }
    vector<int> findNge(vector<int> &nums){
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            ans[i] = !st.empty() ? st.top():n;
            st.push(i);
        }
        return ans;
    }
    vector<int> findPse(vector<int> &nums){
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            ans[i] = !st.empty() ? st.top():-1;
            st.push(i);
        }
        return ans;
    }
    vector<int> findPge(vector<int> &nums){
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            ans[i] = !st.empty() ? st.top():-1;
            st.push(i);
        }
        return ans;
    }
    long long sumMin(vector<int> &nums){
        vector<int> nse = findNse(nums);
        vector<int> pse = findPse(nums);
        long long sum = 0;
        for(int i=0;i<nums.size();i++){
            int left = i-pse[i];
            int right = nse[i]-i;
            long long freq = left*right*1LL;
            long long val = freq*nums[i]*1LL;
            sum+=val;
        }
        return sum;
    }
    long long sumMax(vector<int> &nums){
        vector<int> nge = findNge(nums);
        vector<int> pge = findPge(nums);
        long long sum = 0;
        for(int i=0;i<nums.size();i++){
            int left = i-pge[i];
            int right = nge[i]-i;
            long long freq = left*right*1LL;
            long long val = freq*nums[i]*1LL;
            sum+=val;
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        return (sumMax(nums)-sumMin(nums));
    }
};