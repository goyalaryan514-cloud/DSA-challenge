class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int rem = k;
        for(char digit:num){
            while(rem>0 &&!st.empty()&&st.top()>digit){
                st.pop();
                rem--;
            }
            st.push(digit);
        }
        while(rem>0 && !st.empty()){
            st.pop();
            rem--;
        }
        string result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(),result.end());
        int start=0;
        while(start<result.size()&&result[start]=='0'){
            start++;
        }
        if(start==result.size()){
            return "0";
        }
        return result.substr(start);
    }
};