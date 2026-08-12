class Solution {
public:
    const long long MOD = 1000000007;
    long long count(long long base,long long exp){
        long long result = 1;
        while(exp>0){
            if(exp%2==1){
                result = (result*base)%MOD;
            }
            base = (base*base)%MOD;
            exp/=2;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        long long evencount = (n+1)/2;
        long long oddcount = n/2;
        long long evenways = count(5,evencount);
        long long oddways = count(4,oddcount);
        return (evenways*oddways)%MOD;
        
    }
};