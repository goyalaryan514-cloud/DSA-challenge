class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int left = 0;
        int maxlen = 0;
        for(int right=0;right<s.length();right++){
            if(mp.count(s[right])&& mp[s[right]]>=left){
                left = mp[s[right]]+1;
            }
            mp[s[right]]=right;
            maxlen = max(maxlen,right-left+1);
        }
        return maxlen;
    }
};