class Solution {
public:
    long long cal(vector<int>& piles,int speed){
        long long totalH=0;
        for(int i=0;i<piles.size();i++){
            totalH += (piles[i] + speed - 1) / speed;

        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxpile = *max_element(piles.begin(),piles.end());
        int s=1;
        int e=maxpile;
        int ans=maxpile;
        while(s<=e){
            int mid=s+(e-s)/2;
            long long totalH=cal(piles,mid);
            if(totalH<=h){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
        
    }
};