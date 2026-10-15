class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxi = 0;
        int maxif = 0;
        vector<int> freq(26,0);
        for(int right = 0;right<s.size();right++){
            int index = s[right]-'A';
            freq[index]++;
            maxif = max(maxif,freq[index]);
            int curr = right-left+1;
            if(curr-maxif>k){
                freq[s[left]-'A']--;
                left++;
            }
            curr = right-left+1;
            maxi = max(maxi,curr);
        }
        return maxi;
    }
};