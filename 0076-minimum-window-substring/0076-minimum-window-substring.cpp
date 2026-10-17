class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(n>m)return "";
        vector<int> freq(128,0);
        for (char c : t) {
            freq[c]++;
        }
        int left=0;
        int minlen = INT_MAX;
        int required = n;
        int start=0;
        for(int right=0;right<m;right++){
            char c = s[right];
            if(freq[c]>0){
                required--;
            }
            freq[c]--;
            while(required==0){
                int windlen = right-left+1;
                if(windlen<minlen){
                    minlen = windlen;
                    start = left;
                }
                char leftchar = s[left];
                freq[leftchar]++;
                if(freq[leftchar]>0){
                    required++;
                }
                left++;
            }
        }
        if(minlen == INT_MAX)return "";
        return s.substr(start,minlen);
    }
};