class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> freq;
        int left = 0;
        int maxi = 0;
        for(int right=0;right<fruits.size();right++){
            freq[fruits[right]]++;
            while(freq.size()>2){
                freq[fruits[left]]--;
                if(freq[fruits[left]]==0){
                    freq.erase(fruits[left]);
                }
                left++;
            }
            maxi = max(maxi,right-left+1);
        }
        return maxi;
    }
};