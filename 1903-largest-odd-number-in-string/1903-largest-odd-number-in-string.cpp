class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.length();
        int ind=-1;
        for(int i=n-1;i>=0;i--){
            if((num[i]-'0')%2==1){
                ind=i;
                break;
            }
        }
        int i=0;
        while(i<=ind && num[i]=='0')i++;
        return num.substr(i,ind-i+1);
        
    }
};