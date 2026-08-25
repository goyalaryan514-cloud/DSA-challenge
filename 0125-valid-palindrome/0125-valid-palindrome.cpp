class Solution {
public:
    char toLowercase(char ch){
        if(ch>='a' && ch<='z'){
            return ch;
        }
        else{
            ch = ch - 'A' + 'a'; 
        }
        return ch;
    }
    bool isvalid(char ch){
        if(ch>='a'&& ch<='z'||ch>='A'&& ch<='Z'||ch>='0'&& ch<='9'){
            return true;
        }
        else return false;
    }
    bool isPalindrome(string s) {
        string temp = "";
        for(int j=0;j<s.length();j++){
            if(isvalid(s[j])){
                temp.push_back(s[j]);
            }
        }
        s=temp;
        int st = 0;
        int e = s.length()-1;
        while(st<e){
            if(toLowercase(s[st]) != toLowercase(s[e])){
                return false;
            }
            else{
                st++;
                e--;
            }
        }
        return true;
    }
};