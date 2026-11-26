class Solution {
public:
    bool canAliceWin(int n) {
        bool ans = false;
        if(n<10)return false;
        n = n-10;
        for(int i=9;i>0;i--){
            if(n<i)return !ans;
            n=n-i;
            ans = !ans;
        }
        return ans;
    }
};