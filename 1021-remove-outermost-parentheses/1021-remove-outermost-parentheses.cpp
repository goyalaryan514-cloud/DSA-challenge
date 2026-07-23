class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.length();
        string result = "";
        int level=0;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch=='('){
                if(level>0){
                    result+=ch;
                }
                level++;
            }
            else if(ch==')'){
                level--;
                if(level>0){
                    result+=ch;
                }
            }
        }
        return result;
        
    }
};