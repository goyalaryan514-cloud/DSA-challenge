class Solution {
public:
    static bool comparator(pair<int,char> p1 ,pair<int,char> p2){
        if(p1.first>p2.first)return true;
        if(p1.first<p2.first)return false;
        return p1.second<p2.second;
    }
    string frequencySort(string s) {
        pair<int,char> freq[62];
        for (int i = 0; i < 26; i++) {
            freq[i] = {0, char('A' + i)};
        }

        for(int i=0;i<26;i++){
            freq[i+26]={0,i+'a'};
        }
        for (int i = 0; i < 10; i++) {
            freq[i + 52] = {0, char('0' + i)};
        }

        // Count frequency
        for (char ch : s) {
            if (ch >= 'A' && ch <= 'Z') {
                freq[ch - 'A'].first++;
            }
            else if (ch >= 'a' && ch <= 'z') {
                freq[ch - 'a' + 26].first++;
            }
            else if (ch >= '0' && ch <= '9') {
                freq[ch - '0' + 52].first++;
            }
        }
        sort(freq,freq+62,comparator);
        string ans="";
        for(int i=0;i<62;i++){
            if(freq[i].first>0){
                ans += string(freq[i].first, freq[i].second);

            }

        }
        return ans;
        
    }
};