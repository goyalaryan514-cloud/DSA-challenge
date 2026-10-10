class Solution {
public:
    int divide(int dividend, int divisor) {
        bool negative = (dividend<0)^(divisor<0);
        long long dividendAbs = llabs((long long)dividend);
        long long divisorAbs = llabs((long long)divisor);
        long long quotient = 0;
        for(int i=31;i>=0;i--){
            long long chunk = divisorAbs <<i;
            if(chunk<=dividendAbs){
                dividendAbs-=chunk;
                quotient+=(1LL << i);
            }
        }
        long long result = negative ? -quotient:quotient;
        if(result>INT_MAX){
            return INT_MAX;
        }
        if(result<INT_MIN){
            return INT_MIN;
        }
        return result;
    }
};